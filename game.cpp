#include <iostream>
#include <string.h>

using namespace std;

// Prototype
int random(int min, int max);
string upper(string answer);
void showQuiz(string word, string hint);

// Global Variable
int score = 0;
string answer;

int main()
{
  string word[] = {
    "UMBRELLA",
    "TOWEL"
  };

  string hint[] = {
    "Benda yang dipakai saat musim hujan tiba",
    "Benda untuk mengeringkan badan"
  };

  int size = sizeof(word) / sizeof(word[0]);

  for (int i = 0; i < size; i++) {
    cout << "Soal Ke - " << i + 1 << " : " << endl << endl;
    showQuiz(word[i], hint[i]);
  }
}

int random(int min, int max)
{
    return min + (rand() % ( max - min + 1 ));
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
    cout << "Jawaban Kamu Benar" << endl << endl;
    score += 10;
  } else {
    cout << "Jawaban Kamu Salah";
  }
}
