#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;
int main() {
  //  vector <int> c={1, 2, 36};
  //  for (int x : c)
   //     cout << x << endl;
    srand(time(NULL));
    int m, n, ned = 0; //ned-ействительные бюллетни
    cout << "Введите количество кандидатов и бюллетней\n";
    do {
        cout << "2 <= n <= 10: ";
        cin >> n;
    } while (n < 2 || n > 10);
    do {
        cout << "1 <= m <= 1000: ";
        cin >> m;
    } while (m < 1 || m > 1000);
    vector<string> name(n);     //массив для имен кандидатов
    vector<string> bal(m, "");
    vector<int> num(n, 0);              //для количества голосов каждого кандидата
    for (int i = 0; i < n; ++i) { //ввод имен
        cout << "введите " << i + 1 << "-е имя: ";
        cin >> name[i];
        if (name[i] == "wrong" || name[i] == "Wrong") {
            cout << "нельзя имя "<< name[i] <<"\n";
            --i;
            continue;
        }
    }
    /*cout << "Введите бюллетни\n";
    for (int i = 0; i < m; ++i){
        cout << i << ": ";
        cin >> bal[i];
        if (bal[i].size() != n){
            cout << "неверный размер. введите снова\n";
            --i;
        }
    }*/
    //генерация бюллетней
    for (int i = 0; i < m; i++) {
        int a = rand() % (n + 1);
        for (int j = 0; j < n; j++) {
            if (j == 0 && a == n) { //генерация недействительных (с отсутствующими метками)
                bal[i] += ".";
            }
            else if (j == a && a != n) {
                bal[i] += "X";
            }
            else bal[i] += ".";
        }
    }
    cout << "бюллетни:\n";
    for (int i = 0; i < m; ++i){
        cout << bal[i] << "\n";
    }
    for (int i = 0; i < m; ++i) {   //была запись bal[m][j]
        int a = 0;
        char t;
        int place;
        for (int j = 0; j < n; ++j) {
            t = bal[i][j];
            if(t == 'X' || t == 'x') {
                a++;
                place = j;
            }
        }
        if (a != 1)
            ned++;          //недействительный бюллетень
        else {
            num[place]++;   //количество за кандидата j
        }
    }
    //сортировка пузырьком, для сохранения позиции равнозначных элементов
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1; j++) {
            if (num[j] > num[j+1]) {
                swap(num[j], num[j+1]);
                swap(name[j], name[j+1]);
            }
        }
    }
    //round() - математически правильное округление
    for (int i = 0; i < n; i++) {
        cout << name[i] << "  " << num[i] << "  " << round(100 * num[i] / double(m)) << "%\n";
    }
    cout << "недействительны " << ned << "  " << round(100 * ned / double(m)) << "%";
    
    return 0;
}
