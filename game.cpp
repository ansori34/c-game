#include <iostream>
#include <string.h>

using namespace std;

int random(int min, int max);
string upper(string answer);
void showQuiz(string word, string hint);

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

  for (int i = 0; i < 2; i++) {
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

  for (int i = 0; i < length; i++) {
    int rnd = random(0, wordCount);
    cout << temp[rnd] << " ";
    temp.erase(rnd, 1);
    wordCount--;
  }

  cout << endl << "Hint : " << hint << endl;
  cout << endl << "Jawaban = ";
  cin >> answer;

  if (upper(answer) == word) {
    cout << "Jawaban Kamu Benar" << endl << endl;
  } else {
    cout << "Jawaban Kamu Salah";
  }
}
