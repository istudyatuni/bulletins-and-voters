#include <iostream>
#include <ctime>
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
    cout << "бюллетни:\n";
    //генерация и проверка бюллетней
    for (int i = 0; i < m; i++) {
        int a = rand() % (n + 1);
        for (int j = 0; j < n; j++) {
            if (j == 0 && a == n) { //генерация недействительных (с отсутствующими метками)
                bal[i] += ".";
                ned++;    //недействительный бюллетень
            }
            else if (j == a && a != n) {
                bal[i] += "X";
                num[j]++; //количество за кандидата j
            }
            else bal[i] += ".";
        }
        cout << a << ' ' << bal[i] << endl;
    }
    /*for (int i = 0; i < m; ++i) { //с этим циклом дальше выполнение не идет
        int a = 0;
        for (int j = 0; j < n; ++j) {
            char t = bal[m][n];
            if(t == 'X') {
                a++;
            }
        }
        if (a != 1)
            ned++;
    }*/
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
    return 0;
}
