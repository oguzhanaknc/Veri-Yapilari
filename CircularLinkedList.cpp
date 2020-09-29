/*
 * Author : Oğuzhan Akıncı
 *      29.09.2020
 * Email: oguzhanaknc06@gmail.com
 */


#include <iostream>
#include <stdlib.h>

using namespace std;


template<class T>
class  LinkedList{
private:
    // düğüm yapımızı oluşturduğumuz kısım. ( kutular )
    struct n{
        T x;
        n* next;
    };
    typedef n node;
    node * root = (node *)malloc(sizeof(node)); //kök kutumuzu oluşturuyoruz.
    node * iter = (node *)malloc(sizeof(node)); // gezgin kutumuz.
public:
    // Construactor fonksyonumuzda kök elemanımızın değerlerini atıyor ve gezgin kutumuzu root'a eşitliyoruz.
    LinkedList(){
        root->next = root;
        root->x = NULL;
        iter = root; //dairesel bağlı liste olduğu için son eleman NULL değil root'u gösterecek.
    }
    //sona veri ekleme fonksyonu. parametre olarak eklenecek veriyi alıyor.
    void ekle(T data){
        if (root->x == NULL){ //eğer daha önce veri eklenmemişse onu root'a ver diyoruz.
            root->x = data;
        }else{ //eğer veri eklenmişse
            while (iter->next != root){ //Dairesel bağlı liste olduğu için son eleman yok. son elemanın next'i Root'a tekrar gelene kadar gezecek.
                iter = iter->next;
            }
            iter->next = (node *)malloc(sizeof(node)); //ve en sona yeni bir düğüm (kutu) oluştursun.
            iter->next->x = data; //oluşan kutuya değerleri atayalım.
            iter->next->next = root; //Basit bağlı listelerde Null verdiğimiz yere root'u veriyoruz ki listemiz dairesel olsun.
        }
        resetIter(); // gezgin kutumuzu tekrar root'a eşitleyeylim.
    }
    //ekrana yazdırma fonksyonu parametresi yok.
    void yaz(){
        //yazma işleminde ilk elemanı el ile yazıp iter'i root'dan farklı yapmak zorundayız.
        cout << iter->x << endl;
        iter = iter->next;
        while (iter != root){ //son elemana kadar gezgin node (kutu) ilerliyor.
            cout << iter->x << endl; //her elemanın değerini yazdırıyor.
            iter = iter->next;
        }
        resetIter(); //işlem bitince root'a dönüyor.
    }
    // gezgin elemanı başa alma fonksyonu.
    void resetIter(){
            iter = root;
    }
};






int main() {
    //tam sayılarla işlem yapmak
    LinkedList<int> liste;
    liste.ekle(9);
    liste.ekle(98);
    liste.ekle(12);
    liste.ekle(182);
    liste.ekle(136); // dairesel bağlı listeye eleman eklemek.
    liste.yaz();
    // string ifadeler ile işlem yapmak
    LinkedList<char*> listeS;
    listeS.ekle("hasan");
    listeS.ekle("ahmet");
    listeS.ekle("veli");
    listeS.ekle("ali");
    listeS.yaz(); // dairesel bağlı listeyi ekrana yazdırmak
    return 0;
}
