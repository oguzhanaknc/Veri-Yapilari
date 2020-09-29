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
        root->next = NULL;
        root->x = NULL;
        iter = root;
    }
    //sona veri ekleme fonksyonu. parametre olarak eklenecek veriyi alıyor.
    void ekle(T data){
        if (root->x == NULL){ //eğer daha önce veri eklenmemişse onu root'a ver diyoruz.
            root->x = data;
        }else{ //eğer veri eklenmişse
            while (iter->next != NULL){ //son elemana kadar gezgin kutumuz gezsin.
                iter = iter->next;
            }
            iter->next = (node *)malloc(sizeof(node)); //ve en sona yeni bir düğüm (kutu) oluştursun.
            iter->next->x = data; //oluşan kutuya değerleri atayalım.
            iter->next->next = NULL;
        }
        resetIter(); // gezgin kutumuzu tekrar root'a eşitleyeylim.
    }
    //ekrana yazdırma fonksyonu parametresi yok.
    void yaz(){
        while (iter != NULL){ //son elemana kadar gezgin node (kutu) ilerliyor.
            cout << iter->x << endl; //her elemanın değerini yazdırıyor.
            iter = iter->next;
        }
        resetIter(); //işlem bitince root'a dönüyor.
    }
    // gezgin elemanı başa alma fonksyonu.
    void resetIter(){
        iter = root;
    }
    // veri silme.
    T sil(T data){
        node* temp; //geçici düğüm
        T tempData; // geçici veri
        // eğer silinecek eleman root ise;
        if (root->x == data){
            // root'u temp'e al bir sonraki ile yer değiştir tempi sil.
            temp = root;
            root = root->next;
            tempData = temp->x;
            free(temp);
            resetIter();
            return tempData;
        }
        //veriyi bulana kadar gez.
        while (iter->next !=NULL && iter->next->x != data){
            iter = iter->next;
        }
        //eğer silinecek değer bulunamazsa
        if (iter->next == NULL){
            cout << "silinecek değer bulunamadı" << endl;
            resetIter();
            return  NULL;
            // bulunursa
        }else{
            //değeri temp'e al bir sonraki ile yer değiştir tempi sil.
            temp = iter->next;
            iter->next = temp->next;
            tempData = temp->x;
            free(temp);
            resetIter();
            return tempData;
        }
    }
};






int main() {
    //tam sayılarla işlem yapmak
    LinkedList<int> liste;
    liste.ekle(9);
    liste.ekle(98);
    liste.ekle(12);
    liste.ekle(182);
    liste.ekle(99); // bağlı listeye eleman eklemek.
    liste.yaz();
    liste.sil(9); // veri silme fonksyonu
    // string ifadeler ile işlem yapmak
    LinkedList<char*> listeS;
    listeS.ekle("hasan");
    listeS.ekle("ahmet");
    listeS.ekle("veli");
    listeS.ekle("ali");
    listeS.yaz(); // bağlı listeyi ekrana yazdırmak
    liste.yaz();
    return 0;
}
