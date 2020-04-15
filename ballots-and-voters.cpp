#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <vector>
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
    vector<int> num(n);              //для количества голосов каждого кандидата
    if (n >= 2 && n <= 10 && m >= 1 && m <= 1000) {
        for (int i = 0; i < n; ++i) { //ввод имен
            cout << "введите " << i + 1 << "-е имя: ";
            cin >> name[i];
            if (name[i] == "wrong") {
                cout << "нельзя имя wrong\n";
                --i;
                continue;
            }
        }
        cout << "бюллетни:\n";
        //генерация и проверка бюллетней
        for (int i = 0; i < m; i++) {
            string bul = "";
            int a = rand() % (n + 1);
            for (int j = 0; j < n; j++) {
                if (i == 0)
                    num[j] = 0;
                if (j == a) {//генерация недействительных
                    if (a != n) {
                        bul += "X";
                        num[j]++; //количество за кандидата j
                    } else {
                        bul += ".";
                        cout<<"p";
                        ned++; //недействительный бюллетень
                    }
                }
                else
                    bul += ".";
            }
            cout << bul << endl;
        }
    }
    //сортировка
    for (int i = 0; i < n-2; i++) {
      //  int mx = num[i];
        for (int j = 0; j < n-2; j++) {
            if (num[j] > num[j+1]) {
               // mx = num[j];
                swap(num[j], num[j+1]);
                swap(name[j], name[j+1]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << name[i] << "  " << num[i] << "  " << 100 * num[i] / double(m) << "%\n";
    }
    cout << "недействительны " << ned << "  " << 100 * ned / double(m) << "%";
f1:
    return 0;
}
