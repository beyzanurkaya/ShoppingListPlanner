//BEYZA NUR KAYA
//1306170038*

//Program ilk olarak kullaniciyi ana menu ile karsilar. Ana menu 3 islemi gerceklestirme imkani sunar: liste islemleri, liste goruntuleme ve cikis. Liste goruntuleyi secerseniz goruntulemek istediginiz liste numarasini sizden isteyecektir. Goruntulemek istediginiz liste numarasini girdiginizde id numarasi sizin girdiniz olan tum kayitlar gozukecektir. Liste islemlerini sececek olursaniz kullaniciyi 5 secenek bekliyor. İlk secenek listeye urun ekleme. Eger urun eklemeyi secerseniz program sizden hangi listeye kayit yaptiginizi ayırt edebilmek icin liste idsi isteyecektir. sonrasinda program kullanicidan girmek istedigi urun sayisi, urun adi, urun turu ve urun miktarini isteyecektir. her girdiden sonra girilmis olan inputlar bir vectore kaydedilir. eger delete secenegini secerseniz program once size hangi listede islem yapmak istedigini sonra da silmek istediginiz urunu sorar. o urune ait id, urun ismi, urun turu ve urun miktari kayitlari silinir. eger edit secenegini secerseniz program size 3 farkli duzenleme imkani sunar urun adini duzenleme, urun turunu duzenleme ve urun miktarini duzenleme. Program yine duzenleme yapmak istediginiz liste idsini sizden isteyecektir sonrasinda da duzenleme yapmak istediginiz urun ismini. sectiginiz secenege gore urun ismi, urun turu ve urun miktari uzerinden degisiklik yapabilirsiniz. eger mark secenegini secerseniz program sizin satin almis oldugunuz urunleri soracak ve bunu yanina tik isareti koyacaktır ancak bu urun listeden silinmeyecktir. program ayni zamanda size bu islemi geri alma imkani da sunar. eger bu islemi geri almak istiyorsaniz program y harfi girmenizi bekler. bunun sonucunda da urunun yanindaki tik isareti silinir. eger sonlandir secengini secerseniz program ana menuye doner. ana menude de sonlandir secenegini secerseniz program tamamen sonlandirilir.

#include <iostream>
#include <vector>
using namespace std;

class list{
private:
    string id, item, title, quantity;
    int adet;
    vector<string> List;
   
public:
    
    void addItem(){
        
        cout << "Girmek istediginiz urun sayisini giriniz: ";
        cin >> adet;
        
        for (int i = 0; i < adet; i++) {
            cout << "Liste numarasini giriniz: ";
            cin >> id;
            List.push_back(id);
            cout << "Urun ismini giriniz: ";
            cin >> item;
            List.push_back(item);
            cout << "Urun turunu giriniz: ";
            cin >> title;
            List.push_back(title);
            cout << "Urun miktarini giriniz: ";
            cin >> quantity;
            List.push_back(quantity);

        }
    }
    void editItem(){
        string oldItem, newItem;
        int a;
        do {
            
            cout << "Duzenleme yapmak istediginiz basligi seciniz: ";
            cout << "\n1 - Urun Adi\n";
            cout << "2 - Urun Turu\n";
            cout << "3 - Urun Miktari\n";
            cout << "4 - Sonlandir\n";
            cin >> a;
            switch (a) {
                case 1:
                    cout << "Islem yapmak istediginiz liste numarasini giriniz: ";
                    cin >> id;
                    cout << "Duzenleme yapmak istediginiz urun ismini giriniz: ";
                    cin >> oldItem;
                    cout << "Yeni urun ismini giriniz: ";
                    cin >> newItem;
                    for (int i = 0; i < List.size(); i++) {
                        if (i%4 == 0  && List[i] == id && List[i+1] == oldItem) {
                            List[i+1] = newItem;
                        }
                    }
                    break;
                case 2:
                    cout << "Islem yapmak istediginiz liste numarasini giriniz: ";
                    cin >> id;
                    cout << "Duzenleme yapmak istediginiz urun ismini giriniz: ";
                    cin >> oldItem;
                    cout << "Yeni urun turunu giriniz: ";
                    cin >> newItem;
                    for (int i = 0; i < List.size(); i++) {
                        if (i%4 == 0  && List[i] == id && List[i+1] == oldItem) {
                            List[i+2] = newItem;
                        }
                    }
                    break;
                case 3:
                    cout << "Islem yapmak istediginiz liste numarasini giriniz: ";
                    cin >> id;
                    cout << "Duzenleme yapmak istediginiz urun ismini giriniz: ";
                    cin >> oldItem;
                    cout << "Yeni urun miktarini giriniz: ";
                    cin >> newItem;
                    for (int i = 0; i < List.size(); i++) {
                        if (i%4 == 0  && List[i] == id && List[i+1] == oldItem) {
                                List[i+3] = newItem;
                        }
                    }
                    break;
                case 4:
                    cout << "Shopping List Menusune Yonlendiriliyorsunuz.\n";
                    break;
                default:
                    break;
            }
            
        } while (a != 4);
    }
    
    void deleteItem(){
        string deleteItem;
        cout << "Islem yapmak istediginiz liste numarasini giriniz: ";
        cin >> id;
        cout << "Silmek istediginiz urunun ismini giriniz: ";
        cin >> deleteItem;
        
        for (int i = 0; i < List.size(); i++) {
            if (i%4 == 0  && List[i] == id && List[i+1] == deleteItem ) {
                List[i].erase();
                List[i+1].erase();
                List[i+2].erase();
                List[i+3].erase();
            }
        }
    }
    

    void markItem() {
       
        string takenItem, temp;
        string taken = "✓✓✓ "; //tik isareti
        char x;
        
        cout << "Islem yapmak istediginiz liste numarasini giriniz: ";
        cin >> id;
        cout << "Almis oldugunuz urun ismini giriniz: ";
        cin >> takenItem;
        for (int i = 0; i < List.size(); i++) {
            if (i%4 == 0  && List[i] == id && List[i+1] == takenItem ) {
                cout << List[i+1] << endl;
                List[i+1] = takenItem + taken;
                //temp = List[i+3];
                //List[i+3] = "0";
            }
            
        }
        cout << "Bu islemi geri almak ister misiniz? (y/n)";
        cin >> x;
        if (x == 'y' || x == 'Y' ) {
            for (int i = 0; i < List.size(); i++) {
                if (i%4 == 0  && List[i] == id && List[i+1] == (takenItem + taken) ) {
                    List[i+1] = takenItem;
                    //List[i+3] = temp;
                    
                }
            }
        }
    }
    
    void showItem(){
        cout << "Goruntulemek istediginiz listenin numarasini giriniz: ";
        cin >> id;
        cout << "|------------------------------------------------------------------------|" << endl;
        cout << "|"<<"    No |" << "   Item      |"  << "  Title      |"  << "  Quantity  |" << endl;
        cout << "|------------------------------------------------------------------------|" << endl;
        for (int i = 0; i < List.size(); i++) {
            if (i%4 == 0  && List[i] == id ) {
                cout << "|      " << List[i] << "|  " << List[i+1] <<  "|            " << List[i+2] << "|           "  << List[i+3]  <<   "|";
                cout << endl;
            }
        }
        cout << "|------------------------------------------------------------------------|" << endl;
    };
};

int main() {
    
    int main, shopping;
    list liste;
    do {
        cout << "Main Menu\n";
        cout << "1 - Liste islemleri\n";
        cout << "2 - Kayitli Liste Goruntuleme\n";
        cout << "3 - Exit\n";
    
        cin >> main;
        
        switch (main) {
            case 1:
                do {
                    cout << "Liste Islemleri\n";
                    cout << "1 - Urun ekle\n";
                    cout << "2 - Urun duzenle\n";
                    cout << "3 - Urun sil\n";
                    cout << "4 - Urun isaretle\n";
                    cout << "5 - Sonlandir\n";
                                  
                    cin >> shopping;
                    
                    switch (shopping) {
                       case 1:
                            liste.addItem();
                            break;
                        case 2:
                            liste.editItem();
                            break;
                        case 3:
                            liste.deleteItem();
                            break;
                        case 4:
                            liste.markItem();
                            break;
                        case 5:
                            cout << "Ana Menuye Yonlendiriliyorsunuz.\n";
                            break;
                        default:
                            cout << "Lutfen 1-5 arasinda secim yapiniz.\n";
                            break;
                    }
                }
                while (shopping != 5);
                
                break;
            
            case 2:
                liste.showItem();
                break;
            case 3:
                cout << "Iyı Gunler!!\n";
                return 0;
                break;
            default:
                cout << "Lutfen 1-3 arasinda secim yapiniz.\n";
                break;
        }
        
    } while (main != 3);
    
    return 0;
}

/***/
