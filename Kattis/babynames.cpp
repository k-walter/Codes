#include <bits/stdc++.h>
using namespace std;

struct BSTVertex {
  BSTVertex* parent;
  BSTVertex* left;
  BSTVertex* right;
  string key;
  int height;
  int lsize;
  int rsize;
};

class AVL {
private:
	BSTVertex* root;
	int h(BSTVertex* T) { return T == NULL ? -1 : T->height; }
	int size(BSTVertex* T) { return T == NULL ? 0 : (T->lsize + T->rsize + 1); }
	int index(BSTVertex* T, int i, string& v) {
		if (T == NULL) return -1;
		if (v == T->key) return T->lsize + 1 + i;
		if (v < T->key) return index(T->left, i, v); // search left
		return index(T->right, T->lsize + i + 1, v); // search right
	}
	BSTVertex* findMin(BSTVertex* T) {
		if (T == NULL) return NULL; // empty
		if (T->left == NULL) return T; // found!
		return findMin(T->left); // keep finding
	}
	BSTVertex* successor(BSTVertex* T) {
		if (T->right != NULL)
			return findMin(T->right);

		BSTVertex* par = T->parent;
		BSTVertex* cur = T;
		// if not root and moving up left
		while ((par != NULL) && (cur == par->right)) {
			cur = par;
			par = cur->parent;
		}
		return par; // NULL if largest ele, Vertex* otherwise
	}
	/* <DEBUG> */
	// int getHeight(BSTVertex* T) {
	// 	if (T == NULL) return -1;
	// 	return max(getHeight(T->left), getHeight(T->right)) + 1;
	// }
	void inOrder(BSTVertex* T) {
		if (T == NULL) return;
		inOrder(T->left);
		printf("%d %s %d %d\n", index(T->key), T->key.c_str(), T->lsize, T->rsize);
		inOrder(T->right);
	}
	/* </DEBUG> */
	
	BSTVertex* rotateLeft(BSTVertex* T) { // must have right child
		// Swap vertices
		BSTVertex* c = T->right;
		c->parent = T->parent;
		T->parent = c;
		T->right = c->left;
		if (c->left != NULL) c->left->parent = T;
		c->left = T;

		// Update values
	    T->height = max(h(T->left), h(T->right)) + 1;
	    c->height = max(h(c->left), h(c->right)) + 1;
	    T->rsize = c->lsize;
	    c->lsize = T->lsize + T->rsize + 1; // since c->left = T

	    return c;
	}

	BSTVertex* rotateRight(BSTVertex* T) { // must have left child
		BSTVertex* c = T->left;
		c->parent = T->parent;
		T->parent = c;
		T->left = c->right;
		if (c->right != NULL) c->right->parent = T;
		c->right = T;

	    T->height = max(h(T->left), h(T->right)) + 1;
	    c->height = max(h(c->left), h(c->right)) + 1;
	    T->lsize = c->rsize;
	    c->rsize = T->lsize + T->rsize + 1; // since c->right = T

	    return c;
	}

	BSTVertex* insert(BSTVertex* T, const string& v) {
		// Search and initialise at leaf
		if (T == NULL) {
			T = new BSTVertex;
			T->key = v;
			T->parent = T->left = T->right = NULL;
			T->height = T->lsize = T->rsize = 0;
		}
		else if (T->key < v) { // search right
			T->right = insert(T->right, v);
			T->right->parent = T;
			T->rsize++;
		}
		else { // search left
			T->left = insert(T->left, v);
			T->left->parent = T;
			T->lsize++;
		}

		// Balance
		int balance = h(T->left) - h(T->right);
		if (balance == 2) { // left heavy
			balance = h(T->left->left) - h(T->left->right);
			if (balance == -1) // left, right
				T->left = rotateLeft(T->left);
			T = rotateRight(T);
		}
		else if (balance == -2) { // right heavy
			balance = h(T->right->left) - h(T->right->right);
			if (balance == 1) // right, left
				T->right = rotateRight(T->right);
			T = rotateLeft(T);
		}

		// Update height by recursion
		// Updated lsize / rsize in rotate. Grandparents not affected when inserting.
		T->height = max(h(T->left), h(T->right)) + 1;
		return T;
	}

	BSTVertex* remove(BSTVertex* T, string& v) {
		// Search and remove
		if (T == NULL) return T; // not found
		if (T->key < v) // search right
			T->right = remove(T->right, v);
		else if (T->key > v) // search left
			T->left = remove(T->left, v);
		else { // found!
			if (T->left == NULL && T->right == NULL)		// leaf
				T = NULL;
			else if (T->left == NULL && T->right != NULL) {	// right child
				BSTVertex* temp = T;
				T->right->parent = T->parent;
				T = T->right; // bypass and return upwards
				temp = NULL; // delete
			}
			else if (T->left != NULL && T->right == NULL) {	// left child
				BSTVertex* temp = T;
				T->left->parent = T->parent;
				T = T->left; // bypass and return upwards
				temp = NULL; // delete
			}
			else {											// left and right child
				BSTVertex* s = successor(T);
				T->key = s->key;
				T->right = remove(T->right, s->key); // successor must be in right subtree
			}
		}

		// Balance
		if (T != NULL) { // if not leaf or removed
			// Update lsize, rsize first
			T->lsize = size(T->left);
			T->rsize = size(T->right);

			int balance = h(T->left) - h(T->right);
			if (balance == 2) { // left heavy
				balance = h(T->left->left) - h(T->left->right);
				if (balance == -1) // left, right
					T->left = rotateLeft(T->left);
				T = rotateRight(T);
			}
			else if (balance == -2) { // right heavy
				balance = h(T->right->left) - h(T->right->right);
				if (balance == 1) // right, left
					T->right = rotateRight(T->right);
				T = rotateLeft(T);
			}

			// Update height by recursion.
			T->height = max(h(T->left), h(T->right)) + 1;
		}

		return T;
	}
public:
	AVL() { root = NULL; }
	void insert(const string& v) { root = insert(root, v); }
	void remove(string& v) { root = remove(root, v); }
	int index(string& v) { return index(root, 0, v); }
	int smaller(string &v) {
		if (root == NULL) return -1;

		int idx = 0;
		BSTVertex *curr, *prev;
		curr = root;
		while (curr != NULL) {
			if (curr->key == v) // +1 instead of +2 in upper_bound
				return idx + curr->lsize + 1;
			prev = curr;
			if (v > curr->key) { // search right
				idx += curr->lsize + 1;
				curr = curr->right;
			}
			else // search left
				curr = curr->left;
		}

		return idx + 1;
	}
	int distance(string& v1, string& v2) {
		if (v1 >= v2) return 0;
		return smaller(v2) - smaller(v1);
	}
	/* <DEBUG> */
	// int getHeight() { return getHeight(root); }
	void inOrder() { inOrder(root); }
	/* </DEBUG> */
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("babynames.in", "r", stdin);

	unordered_set<string> m_name(2e5*2);
	AVL m,f;
	int n, sex;
	string name;

	while (cin>>n, n) {
		switch (n) {
			case 1:
				cin >> name >> sex;
				if (sex == 1) {
					m.insert(name);
					m_name.insert(name);
					// m.inOrder();
				} else {
					f.insert(name);
					// f.inOrder();
				}
				break;
			case 2:
				cin >> name;
				if (m_name.find(name) == m_name.end()) {
					f.remove(name);
				} else {
					m.remove(name);
					m_name.erase(name);
				}
				break;
			case 3:
				string a,b; int sex; cin >> a >> b >> sex;
				int sum = 0;
				switch (sex) {
					case 0:
						sum += f.distance(a, b);
					case 1:
						sum += m.distance(a, b);
						break;
					case 2:
						sum += f.distance(a, b);
						break;
				}
				cout << sum << "\n";
				break;
		}
	}

	return 0;
}