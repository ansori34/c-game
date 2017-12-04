#include <iostream>
#include <string.h>

using namespace std;

/**
  random = Untuk generate angka Random dengan range tertentu
  getScore = Untuk melakukan perhitungan skor
  upper = Untuk membuat inputan user menjadi Huruf Kapital
  showQuiz = untuk menampilkan Quiz
*/
int random(int min, int max);
int getScore();
string upper(string answer);
void showQuiz(string word, string hint);

/**
  correct = Untuk Menghitung jumlah Jawaban Benar
  wrong = Untuk Menghitung jumlah Jawaban Salah
  winScore = Jumlah skor minimal untuk menang
*/
int correct = 0, wrong = 0, winScore = 35;
string answer;

int main()
{
  string word[] = {
    "UMBRELLA",
    "TOWEL",
    "STRAWBERRY",
    "WARDROBE",
    "ELEPHANT"
  };

  string hint[] = {
    "Benda yang dipakai saat musim hujan tiba",
    "Benda untuk mengeringkan badan",
    "Buah yang memiliki warna umum merah dan berbintik",
    "Benda untuk menyimpan pakaian",
    "Hewan yang memiliki ukuran tubuh besar"
  };

  int size = sizeof(word) / sizeof(word[0]);

  for (int i = 0; i < size; i++) {
    cout << "Soal Ke - " << i + 1 << " : " << endl << endl;
    showQuiz(word[i], hint[i]);
  }

  cout << "Jawaban Benar = " << correct << endl;
  cout << "Jawaban Salah = " << wrong << endl << endl;

  cout << "Skor Akhir = " << getScore() << endl;
  cout << "Skor Minimal = " << winScore << endl;

  if (getScore() >= winScore) {
    cout << endl << "Horee, Kamu Menang :)";
  } else {
    cout << endl << "Yah, Kamu Kalah :(";
  }
}

int random(int min, int max)
{
    return min + (rand() % ( max - min + 1 ));
}

int getScore()
{
  return (correct * 10) - (wrong * 5);
}

string upper(string answer)
{
  for (int i = 0; i < answer.length(); i++) {
    answer[i] = toupper(answer[i]);
  }

  return answer;
}

void showQuiz(string word, string hint)
{
  string temp = word;
  int length = word.length(), wordCount = length - 1;

  srand(time(NULL));

  cout << "=================================================" << endl << endl;

  for (int i = 0; i < length; i++) {
    int rnd = random(0, wordCount);
    cout << temp[rnd] << " ";
    temp.erase(rnd, 1);
    wordCount--;
  }

  cout << endl << "Hint : " << hint << endl;
  cout << endl << "=================================================";
  cout << endl << "Jawaban = ";
  cin >> answer;

  if (upper(answer) == word) {
    correct++;
  } else {
    wrong++;
  }

  system("clear");
}
