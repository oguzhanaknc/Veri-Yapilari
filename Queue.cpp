/*
 * Author : Oğuzhan Akıncı
 *      29.09.2020
 * Email: oguzhanaknc06@gmail.com
 */


#include <iostream>
#include <stdlib.h>

using namespace std;


template<class T>
class  Queue{
private:
    // düğüm yapımızı oluşturduğumuz kısım. ( kutular )
    struct n{
        T x;
        n* next;
    };
    typedef n node;
    node * root = (node *)malloc(sizeof(node)); //kök kutumuzu oluşturuyoruz.
    node * iter = (node *)malloc(sizeof(node)); // gezgin kutumuz.
    node * tail = (node *)malloc(sizeof(node)); // Sondan bir önceki kutu.
public:
    // Construactor fonksyonumuzda kök elemanımızın değerlerini atıyor ve gezgin kutumuzu root'a eşitliyoruz.
    Queue(){
        root->next = NULL;
        root->x = NULL;
        iter = root;
        tail = root;
    }
    //sona veri ekleme fonksyonu. parametre olarak eklenecek veriyi alıyor.
    void Push(T data){
        if (root->x == NULL){ //eğer daha önce veri eklenmemişse onu root'a ver diyoruz.
            root->x = data;
        }else{ //eğer veri eklenmişse
            while (iter->next != NULL){ //son elemana kadar gezgin kutumuz gezsin.
                iter = iter->next;
            }
            iter->next = (node *)malloc(sizeof(node)); //ve en sona yeni bir düğüm (kutu) oluştursun.
            iter->next->x = data; //oluşan kutuya değerleri atayalım.
            tail = iter; // son kutuyu kaydırıyoruz.
            iter->next->next = NULL;
        }
        resetIter(); // gezgin kutumuzu tekrar root'a eşitleyeylim.
    }
    //ekrana yazdırma fonksyonu parametresi yok.
    void yaz(){
        resetIter();
        while (iter != NULL){ //son elemana kadar gezgin node (kutu) ilerliyor.
            cout << iter->x << endl; //her elemanın değerini yazdırıyor.
            iter = iter->next;
        }

    }
    // gezgin elemanı başa alma fonksyonu.
    void resetIter(){
        iter = root;
    }
    // Pop() Son ilk sil ve döndür.
    T Pop()  {
        resetIter(); //gezgin kutuyu sıfırla
        if (root->x == NULL){ //liste dolu mu boş mu bak.
            cout << "Boş Stack Silinemez..." << endl;
            return -1;
        }
        node * temp; //temp oluştur
        T tempdata;
        temp = root; //root'u bir kaydırıyoruz.
        tempdata = root->x;
        root = root->next;
        free(temp); //temp'i hafızadan sil
        resetIter(); // gezgini sıfırla
        return tempdata; // değeri döndür


    }
    // Top() ilk veriyi silmeden döndür.
    T Top(){
        return root->x;
    }
};






int main() {
    //tam sayılarla işlem yapmak
    Queue<int> liste;
    liste.Push(9);
    liste.Push(98);
    liste.Push(12);
    liste.Push(182);
    liste.Push(99); // bağlı listeye eleman eklemek.
    liste.yaz();
    cout << "*/*/*/*/*/*/" << endl;
    cout << liste.Pop() << endl; // veri silme fonksyonu
    cout << "*/*/*/*/*/*/" << endl;
    liste.yaz();
    cout << "*/*/*/*/*/*/" << endl;
    cout << liste.Top() << endl;
    return 0;
}