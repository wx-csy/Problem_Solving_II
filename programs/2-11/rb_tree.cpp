#include <iostream>
using namespace std;

const bool RED   = true;
const bool BLACK = false;

template <typename T>
struct rb_tree{
    struct node{
        T key;
        node* parent;
        node* left;
        node* right;
        bool color;
    };

    node* NIL;
    node* root;

    rbtree(){
        NIL = new node;
        NIL->color = BLACK;
        root = NIL;
        return this;
    }

private:
    void left_rotate(node* x){
        node* y = x->right;
        x->right = y->left;
        if (y->left != NIL){
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == NIL){
            root = y;
        } else if(x == x->parent->left){
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void right_rotate(node* x){
        node* y = x->left;
        x->left = y->right;
        if (y->right != NIL){
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == NIL){
            root = y;
        } else if(x == x->parent->right){
            x->parent->right = y;
        } else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }

    void insert_fixup(node* z){
        node* y;
        while (z->parent->color == RED){
            if (z->parent == z->parent->parent->left){
                y = z->parent->parent->right;
                if (y->color == RED){
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->right){
                        z = z->parent;
                        left_rotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    right_rotate(z->parent->parent);
                }
            } else {
                y = z->parent->parent->left;
                if (y->color == RED){
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->left){
                        z = z->parent;
                        right_rotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    left_rotate(z->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

    void transplant(node* u, node* v){
        if (u->parent == NIL){
            root = v;
        } else if(u == u->parent->left){
            u->parent->left = v;
        } else{
            u->parent->right = v;
        }
        v->parent = u->parent;
    }

    void delete_fixup(node* x){
        node* w;
        while (x != root && x->color == BLACK){
            if (x == x->parent->left){
                w = x->parent->right;
                if (w->color == RED){
                    w->color = BLACK;
                    x->parent->color = RED;
                    left_rotate(x->parent);
                    w = x->parent->right;
                }
                if (w->left->color == BLACK && w->right->color == BLACK){
                    w->color = RED;
                    x = x->parent;
                } else {
                    if (w->right->color == BLACK){
                        w->left->color = BLACK;
                        w->color = RED;
                        right_rotate(w);
                        w = x->parent->right;
                    }
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->right->color = BLACK;
                    left_rotate(x->parent);
                    x = root;
                }
            } else {
                w = x->parent->left;
                if (w->color == RED){
                    w->color = BLACK;
                    x->parent->color = RED;
                    right_rotate(x->parent);
                    w = x->parent->left;
                }
                if (w->right->color == BLACK && w->left->color == BLACK){
                    w->color = RED;
                    x = x->parent;
                } else {
                    if (w->left->color == BLACK){
                        w->right->color = BLACK;
                        w->color = RED;
                        left_rotate(w);
                        w = x->parent->left;
                    }
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->left->color = BLACK;
                    right_rotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }

public:
    node* insert(T key){
        node* z = new node;
        z->key = key;
        node* y = NIL;
        node* x = root;
        while (x != NIL){
            y = x;
            if (z->key < x->key){
                x = x->left;
            } else {
                x = x->right;
            }
        }
        z->parent = y;
        if (y == NIL){
            root = z;
        } else if (z->key < y->key){
            y->left = z;
        } else {
            y->right = z;
        }
        z->left = NIL;
        z->right = NIL;
        z->color = RED;
        insert_fixup(z);
        return z;
    }

    // RB-Delete
    void remove(node* z){
        node* y = z;
        node* x;

        bool y_original_color = y->color;
        if (z->left == NIL){
            x = z->right;
            transplant(z, z->right);
        } else if (z->right == NIL){
            x = z->left;
            transplant(z, z->left);
        } else{
            y = z->right;
            while (y->left != NIL) y = y->left; // Tree-Minimum
            y_original_color = y->color;
            x = y->right;
            if (y->parent == z){
                x->parent = y;
            } else {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        if (y_original_color == BLACK){
            delete_fixup(x);
        }
    }
};

int main(){

    return 0;
}
