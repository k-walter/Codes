/*
	V: any type of your choosing, with operators < = > defined
	(check out operator overloading for more information)
	it is customary to use the variable name "T" for the typename
	but since you already used that in other parts of your code, i use V

	changed "V" to "V"

	added const for additional safety for incoming values to be processed
*/

template <typename V>
struct BSTVertex {
  BSTVertex<V>* parent;
  BSTVertex<V>* left;
  BSTVertex<V>* right;
  V key;
  int height;
  int lsize;
  int rsize;
};

template <typename V>
class AVL {
private:
    BSTVertex<V>* root;
    int h(BSTVertex<V>* T) { return T == NULL ? -1 : T->height; }
    int size(BSTVertex<V>* T) { return T == NULL ? 0 : (T->lsize + T->rsize + 1); }
    int index(BSTVertex<V>* T, int i, const V& v) {
        if (T == NULL) return -1;
        if (v == T->key) return T->lsize + 1 + i;
        if (v < T->key) return index(T->left, i, v); // search left
        return index(T->right, T->lsize + i + 1, v); // search right
    }
    BSTVertex<V>* findMin(BSTVertex<V>* T) {
        if (T == NULL) return NULL; // empty
        if (T->left == NULL) return T; // found!
        return findMin(T->left); // keep finding
    }
    BSTVertex<V>* successor(BSTVertex<V>* T) {
        if (T->right != NULL)
            return findMin(T->right);

        BSTVertex<V>* par = T->parent;
        BSTVertex<V>* cur = T;
        // if not root and moving up left
        while ((par != NULL) && (cur == par->right)) {
            cur = par;
            par = cur->parent;
        }
        return par; // NULL if largest ele, Vertex* otherwise
    }
    /* <DEBUG> */
    // int getHeight(BSTVertex<V>* T) {
    //  if (T == NULL) return -1;
    //  return max(getHeight(T->left), getHeight(T->right)) + 1;
    // }
    void inOrder(BSTVertex<V>* T) {
        if (T == NULL) return;
        inOrder(T->left);
        cout << T->key << " ";
        // printf("%d %s %d %d\n", index(T->key), T->key.c_str(), T->lsize, T->rsize);
        inOrder(T->right);
    }
    /* </DEBUG> */
    
    BSTVertex<V>* rotateLeft(BSTVertex<V>* T) { // must have right child
        // Swap vertices
        BSTVertex<V>* c = T->right;
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

    BSTVertex<V>* rotateRight(BSTVertex<V>* T) { // must have left child
        BSTVertex<V>* c = T->left;
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

    BSTVertex<V>* insert(BSTVertex<V>* T, const V& v) {
        // Search and initialise at leaf
        if (T == NULL) {
            T = new BSTVertex<V>;
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

    BSTVertex<V>* remove(BSTVertex<V>* T, const V& v) {
        // Search and remove
        if (T == NULL) return T; // not found
        if (T->key < v) // search right
            T->right = remove(T->right, v);
        else if (T->key > v) // search left
            T->left = remove(T->left, v);
        else { // found!
            if (T->left == NULL && T->right == NULL)        // leaf
                T = NULL;
            else if (T->left == NULL && T->right != NULL) { // right child
                BSTVertex<V>* temp = T;
                T->right->parent = T->parent;
                T = T->right; // bypass and return upwards
                temp = NULL; // delete
            }
            else if (T->left != NULL && T->right == NULL) { // left child
                BSTVertex<V>* temp = T;
                T->left->parent = T->parent;
                T = T->left; // bypass and return upwards
                temp = NULL; // delete
            }
            else {                                          // left and right child
                BSTVertex<V>* s = successor(T);
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
    void insert(const V& v) { root = insert(root, v); }
    void remove(const V& v) { root = remove(root, v); }
    int index(const V& v) { return index(root, 0, v); }
    int smaller(const V &v) {
        if (root == NULL) return -1;

        int idx = 0;
        BSTVertex<V> *curr, *prev;
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
    int distance(const V& v1, const V& v2) {
        if (v1 >= v2) return 0;
        return smaller(v2) - smaller(v1);
    }
    /* <DEBUG> */
    // int getHeight() { return getHeight(root); }
    void inOrder() { inOrder(root); cout << endl;}
    /* </DEBUG> */
};