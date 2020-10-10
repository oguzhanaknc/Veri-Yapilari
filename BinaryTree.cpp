/*
 * Author : Oğuzhan Akıncı
 *      29.09.2020
 * Email: oguzhanaknc06@gmail.com
 */


#include <iostream>
#include <stdlib.h>

using namespace std;



class   BinaryTree{
private:

    struct n{
        int x;
        n* left;
        n* right;
    };
    typedef n node;
    node * root = (node *)malloc(sizeof(node));
    void iter(node* tree){
        if (tree == NULL){
            return;
        }
        iter(tree->left);
        cout << tree->x << ",";
        iter(tree->right);
    } //ağaç içinde gezinme
    node* add(int data, node * tree){
        if (tree == NULL){
            node * temp = (node *)malloc(sizeof(node));
            tree = temp;
            tree->x = data;
            tree->right = NULL;
            tree->left = NULL;
            return tree;
        }
        if (tree->x < data ){
            tree->right = add(data,tree->right);
            return tree;
        }
        tree->left = add(data,tree->left);
        return tree;
    } //Sıralı eleman ekleme
    bool find(node* tree,int data){
        if (tree == NULL){
            return false;
        }
        if (tree->x == data){
            return true;
        }
        if (find(tree->left,data)){
            return true;
        };
        if (find(tree->right,data)){
            return true;
        };
        return false;
    } //ağaç içinde arama

public:
    BinaryTree(){
        root->left = NULL;
        root->right = NULL;
        root->x = NULL;
    }
    void Add( int  data){
        if (root->x ==  NULL){
            root->x = data;
        }else{
            root = add(data,root);
        }
    }
    void toString(){
        iter(root);
    }
    bool any(int data){
        return find(root,data);
    }
};






int main() {
    BinaryTree liste;
    liste.Add(5);
    liste.Add(6);
    liste.Add(4);
    liste.Add(12);
    liste.Add(1);
    liste.Add(89);
    liste.Add(8);
    liste.Add(3);
    liste.Add(7);
    liste.toString(); //ağaçları yazdırma
    cout << liste.any(8) << endl; //ağaç içinde arama


    return 0;
}