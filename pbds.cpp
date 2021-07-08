using namespace __gnu_pbds; 

template <typename T>
using pbds_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

pbds_set<int> os;
os.erase();
os.insert();
os.order_of_key();
