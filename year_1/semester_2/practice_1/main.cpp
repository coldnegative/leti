#define CLEARSCREEN "clear"

#include <memory>
#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <limits>

struct student
  {
    char Name[101];
    short Sex;
    char Group[11];
    short Number;
    short Ekz1;
    short Ekz2;
    short Ekz3;
    short Diff1;
    short Diff2;
    short Diff3;
    short Diff4;
    short Diff5;
    short Form;
    time_t modificationTime;
  };

student* mainMenu (student *List);
student* addStudentFromTerminal (student *List);
int getNumericAnswer (int minRange, int maxRange, const char *question);
student* addStudentsFromFile (student *List);
student* dismissStudent (student *List, unsigned int studentNumber);
void studentList (student *List);
void studentMenu (student *List, unsigned int studentNumber);
void printStudentInfo (student *List, unsigned int studentNumber);
void dumpListToFile (student *List);
void studentGradesMenu (student *Student);
void changeStudentGrades (student *Student, short request);
void changeStudentName (student *Student, bool isNew);
void changeStudentSex (student *Student, bool isNew);
void changeStudentGroup (student *Student, bool isNew);
void changeStudentNumber (student *Student, bool isNew);
void changeStudentForm (student *Student, bool isNew);
void listFilterChoise (student *List);
void listFilter (student *List, bool length);
void listGroup (student *List, bool length, const char *Group);
void listTop (student *List, bool length);
void listSex (student *List, bool length);
void listStipend (student *List, bool length);
void listStipendless (student *List, bool length);
void listFourFive (student *List, bool length);
void listFive (student *List, bool length);
void listNumber (student *List, bool length, int Number);
void listTime (student *List, bool length, tm Begin, int Noon);
tm getTmDate ();

using namespace std;

unsigned int listSize;

int main ( void ) {
    setlocale(LC_ALL, "Russian");
    listSize=0;
    student *List=NULL;
    List=mainMenu (List);
    free(List);
    return EXIT_SUCCESS;
}

student* mainMenu (student *List)
  {
    system (CLEARSCREEN);
    cout << "Главное меню:" << "\n\n" << "1) Вывести полны"
                 "й список студентов." << "\n" << "2) Добавить студента из"
                 " терминала." << "\n" << "3) Добавить студентов из файла."
                 << "\n" << "4) Вывести список студентов по фильтру." <<
                 "\n" << "5) Вывод всех данных в файл." << "\n" <<
                 "0) Выход из программы." << "\n" << "\n";
    switch (getNumericAnswer (0, 5, "Введите номер желаемого варианта: "))
      {
        case 1:
          studentList(List);
          List=mainMenu(List);
          break;
        case 2:
          List=addStudentFromTerminal(List);
          List=mainMenu(List);
          break;
        case 3:
          List=addStudentsFromFile(List);
          List=mainMenu(List);
          break;
        case 4:
          listFilterChoise(List);
          List=mainMenu(List);
          break;
        case 5:
          dumpListToFile(List);
          List=mainMenu(List);
          break;
        default:
          break;
      }
    return List;
  }

student* addStudentFromTerminal (student *List)
  {
    system (CLEARSCREEN);
    cout << "Добавление студента:" << "\n" << "\n";
    listSize++;
    List=(student*)realloc(List, listSize*sizeof(student));
    student *Student=List+listSize-1;
    changeStudentName(Student, 1);
    cout << "\n";
    changeStudentSex(Student, 1);
    cout << "\n";
    changeStudentGroup(Student, 1);
    cout << "\n";
    changeStudentNumber(Student, 1);
    cout << "\n";
    changeStudentGrades(Student, 1);
    cout << "\n";
    changeStudentGrades(Student, 2);
    cout << "\n";
    changeStudentGrades(Student, 3);
    cout << "\n";
    changeStudentGrades(Student, 4);
    cout << "\n";
    changeStudentGrades(Student, 5);
    cout << "\n";
    changeStudentGrades(Student, 6);
    cout << "\n";
    changeStudentGrades(Student, 7);
    cout << "\n";
    changeStudentGrades(Student, 8);
    cout << "\n";
    changeStudentForm(Student, 1);
    Student->modificationTime=time (NULL);
    return List;
  }

int getNumericAnswer (int minRange, int maxRange, const char *Question)
  {
    int answer;
    cout << Question;
    cin >> answer;
    if ((cin.fail())||(answer<minRange)||(answer>maxRange))
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Некорректный ввод!" << "\n";
        answer=getNumericAnswer (minRange, maxRange, Question);
        return answer;
      }
    else
      {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return answer;
      }
  }

student* addStudentsFromFile (student *List)
  {
    char fileName[261];
    cout << "\n" << "Введите имя (или путь) файла (по умолчанию - students): ";
    cin.getline (fileName, 261);
    if (fileName[0]=='\0') strcpy(fileName, "students");
    ifstream File;
    File.open (fileName);
    if (File.is_open())
      {
        while (!File.eof())
          {
            listSize++;
            List=(student*)realloc(List, listSize*sizeof(student));
            student *newStudent;
            newStudent=List+listSize-1;
            File.getline (newStudent->Name, 101);
            File >> newStudent->Sex;
            File.ignore(numeric_limits<streamsize>::max(), '\n');
            File.getline (newStudent->Group, 11);
            File >> newStudent->Number;
            File.ignore(numeric_limits<streamsize>::max(), '\n');
            File >> newStudent->Ekz1;
            File.ignore(numeric_limits<streamsize>::max(), '\n');
            File >> newStudent->Ekz2;
            File.ignore(numeric_limits<streamsize>::max(), '\n');
            File >> newStudent->Ekz3;
            File.ignore(numeric_limits<streamsize>::max(), '\n');
            File >> newStudent->Diff1;
            File.ignore(numeric_limits<streamsize>::max(), '\n');
            File >> newStudent->Diff2;
            File.ignore(numeric_limits<streamsize>::max(), '\n');
            File >> newStudent->Diff3;
            File.ignore(numeric_limits<streamsize>::max(), '\n');
            File >> newStudent->Diff4;
            File.ignore(numeric_limits<streamsize>::max(), '\n');
            File >> newStudent->Diff5;
            File.ignore(numeric_limits<streamsize>::max(), '\n');
            File >> newStudent->Form;
            File.ignore(numeric_limits<streamsize>::max(), '\n');
            File >> newStudent->modificationTime;
            File.ignore(numeric_limits<streamsize>::max(), '\n');
          }
        File.close();
      }
    else
      {
        cout << "Некорректный ввод!" << "\n";
        List=addStudentsFromFile(List);
      }
    return List;
  }

void studentList (student *List)
  {
    system (CLEARSCREEN);
    cout << "Список студентов в базе:" << "\n" << "\n";
    for (unsigned int i=0; i<listSize; i++)
      {
        cout << i+1 << ". " << (List+i)->Name << "\n";
      }
    cout << "\n";
    int answer=getNumericAnswer(0, listSize, "Введите номер студента в списке, карточку которого вы хотите посмотреть (для возврата в главное меню введите 0): ");
    if (answer)
      {
        studentMenu (List, answer);
        studentList (List);
      }
  }

void studentMenu (student *List, unsigned int studentNumber)
  {
    system (CLEARSCREEN);
    printStudentInfo (List, studentNumber);
    cout << "\n" << "\n" << "Меню работы с данными студента:" <<
                 "\n" << "\n" << "1) Изменить сведения о ФИО студента"
                 "." << "\n" << "2) Изменить сведения о поле студента." <<
                 "\n" << "3) Изменить сведения о группе студента." <<
                 "\n" << "4) Изменить сведения о номере студента в списке "
                 "группы." << "\n" << "5) Изменить сведения об оценках сту"
                 "дента." << "\n" << "6) Изменить сведения о форме обучени"
                 "я студента." << "\n" << "0) Вернуться в главное меню." <<
                 "\n" << "\n";
    student *Student=List+studentNumber-1;
    switch (getNumericAnswer (0, 6, "Введите номер желаемого варианта: "))
      {
        case 1:
          changeStudentName (Student, 0);
          Student->modificationTime=time(NULL);
          studentMenu (List, studentNumber);
          break;
        case 2:
          changeStudentSex (Student, 0);
          Student->modificationTime=time(NULL);
          studentMenu (List, studentNumber);
          break;
        case 3:
          changeStudentGroup (Student, 0);
          Student->modificationTime=time(NULL);
          studentMenu (List, studentNumber);
          break;
        case 4:
          changeStudentNumber (Student, 0);
          Student->modificationTime=time(NULL);
          studentMenu (List, studentNumber);
          break;
        case 5:
          studentGradesMenu (Student);
          studentMenu (List, studentNumber);
          break;
        case 6:
          changeStudentForm (Student, 0);
          Student->modificationTime=time(NULL);
          studentMenu (List, studentNumber);
          break;
        default:
          break;
      }
  }

void printStudentInfo (student *List, unsigned int studentNumber)
  {
    student *Student=List+studentNumber-1;
    cout << "Студент " << studentNumber << "\n" << "\n" << "ФИО "
                 "студента: " << Student->Name << "\n" << "Пол студента:";
    switch (Student->Sex)
      {
        case 1:
          cout << " мужской.";
          break;
        default:
          cout << " женский.";
          break;
      }
    cout << "\n" << "Номер группы студента: " << Student->Group <<
                 "\n" << "Номер студента в списке группы: " <<
                 Student->Number << "\n" << "Оценка студента за первый экз"
                 "амен: " << Student->Ekz1 << "\n" << "Оценка студента за "
                 "второй экзамен: " << Student->Ekz2 << "\n" << "Оценка ст"
                 "удента за третий экзамен: " << Student->Ekz3 << "\n" <<
                 "Оценка студента за первый зачёт: " << Student->Diff1 <<
                 "\n" << "Оценка студента за второй зачёт: " <<
                 Student->Diff2 << "\n" << "Оценка студента за третий зачё"
                 "т: " << Student->Diff3 << "\n" << "Оценка студента за че"
                 "твёртый зачёт: " << Student->Diff4 << "\n" << "Оценка ст"
                 "удента за пятый зачёт: " << Student->Diff5 << "\n" <<
                 "Форма обучения студента: ";
    switch (Student->Form)
      {
        case 1:
          cout << "очная.";
          break;
        case 2:
          cout << "очно-заочная.";
          break;
        default:
          cout << "заочная.";
          break;
      }
      cout << "\n" << "Дата внесения изменений в запись: " <<
                   asctime(localtime(&Student->modificationTime));
  }

void changeStudentName (student *Student, bool isNew)
  {
    if (!isNew) cout << "\n" << "Текущие сведения о ФИО студента: " <<
                             Student->Name << "\n";
    cout << "Введите ФИО студента: ";
    cin.getline (Student->Name, 101);
  }

void changeStudentSex (student *Student, bool isNew)
  {
    if (!isNew) 
      {
        cout << "\n" << "Текущие сведения о поле студента: ";
        switch (Student->Sex)
          {
            case 1:
              cout << "мужской." << "\n";
              break;
            default:
              cout << "женский." << "\n";
              break;
          }
      }
    cout << "Выберите пол студента:" << "\n" << "1) мужской пол." <<
                 "\n" << "2) женский пол." << "\n";
    Student->Sex=getNumericAnswer (1, 2, "Введите номер желаемого варианта: ");
  }

void changeStudentGroup (student *Student, bool isNew)
  {
    if (!isNew) cout << "\n" << "Текущие сведения о группе студента: "
                          << Student->Group << "\n";
    cout << "Введите номер группы студента: ";
    cin.getline (Student->Group, 11);
  }

void changeStudentNumber (student *Student, bool isNew)
  {
    if (!isNew) cout << "\n" << "Текущие сведения о номере студента в"
                             " списке группы: " << Student->Number << "\n";
    Student->Number=getNumericAnswer(0, 100, "Введите номер студента в списке группы: ");
  }

void studentGradesMenu (student *Student)
  {
    system (CLEARSCREEN);
    cout << "Оценки студента: " << "\n" << "\n" << "Оценка студента за первый э"
                 "кзамен: " << Student->Ekz1 << "\n" << "Оценка студента за второй э"
                 "кзамен: " << Student->Ekz2 << "\n" << "Оценка студента за третий э"
                 "кзамен: " << Student->Ekz3 << "\n" << "Оценка студента за первый з"
                 "ачёт: " << Student->Diff1 << "\n" << "Оценка студента за второй за"
                 "чёт: " << Student->Diff2 << "\n" << "Оценка студента за третий зач"
                 "ёт: " << Student->Diff3 << "\n" << "Оценка студента за четвёртый з"
                 "ачёт: " << Student->Diff4 << "\n" << "Оценка студента за пятый зач"
                 "ёт: " << Student->Diff5 << "\n" << "\n" << "Вы хотите изменить све"
                 "дения о зачёте или экзамене?" << "\n" << "1) Изменить оценку за за"
                 "чёт." << "\n" << "2) Изменить оценку за экзамен." << "\n" << "0) В"
                 "ернуться в предыдущее меню." << "\n";
    switch (getNumericAnswer(0, 2, "Введите номер желаемого варианта: "))
      {
        case 1:
          switch (getNumericAnswer(1,5,"Введите номер зачёта, оценку за который вы желаете изменить: "))
            {
              case 1:
                changeStudentGrades(Student, 4);
                break;
              case 2:
                changeStudentGrades(Student, 5);
                break;
              case 3:
                changeStudentGrades(Student, 6);
                break;
              case 4:
                changeStudentGrades(Student, 7);
                break;
              default:
                changeStudentGrades(Student, 8);
                break;
            }
          Student->modificationTime=time (NULL);
          studentGradesMenu (Student);
          break;
        case 2:
          switch (getNumericAnswer(1,3,"Введите номер экзамена, оценку за который вы желаете изменить: "))
            {
              case 1:
                changeStudentGrades(Student, 1);
                break;
              case 2:
                changeStudentGrades(Student, 2);
                break;
              default:
                changeStudentGrades(Student, 3);
                break;
            }
          Student->modificationTime=time (NULL);
          studentGradesMenu (Student);
          break;
        default:
          break;
      }
  }

void changeStudentGrades (student *Student, short request)
  {
    switch (request)
      {
        case 1:
          Student->Ekz1=getNumericAnswer(2, 5, "Пожалуйста, введите оценку студента за первый экзамен: ");
          break;
        case 2:
          Student->Ekz2=getNumericAnswer(2, 5, "Пожалуйста, введите оценку студента за второй экзамен: ");
          break;
        case 3:
          Student->Ekz3=getNumericAnswer(2, 5, "Пожалуйста, введите оценку студента за третий экзамен: ");
          break;
        case 4:
          Student->Diff1=getNumericAnswer(2, 5, "Пожалуйста, введите оценку студента за первый зачёт: ");
          break;
        case 5:
          Student->Diff2=getNumericAnswer(2, 5, "Пожалуйста, введите оценку студента за второй зачёт: ");
          break;
        case 6:
          Student->Diff3=getNumericAnswer(2, 5, "Пожалуйста, введите оценку студента за третий зачёт: ");
          break;
        case 7:
          Student->Diff4=getNumericAnswer(2, 5, "Пожалуйста, введите оценку студента за четвёртый зачёт: ");
          break;
        case 8:
          Student->Diff5=getNumericAnswer(2, 5, "Пожалуйста, введите оценку студента за пятый зачёт: ");
          break;
      }
  }

void changeStudentForm (student *Student, bool isNew)
  {
    if (!isNew)
      {
        cout << "\n" << "Текущие сведения о форме обучения студента: ";
        switch (Student->Form)
          {
            case 3:
              cout << "заочная форма." << "\n";
              break;
            case 2:
              cout << "очно-заочная форма." << "\n";
              break;
            default:
              cout << "очная форма." << "\n";
              break;
          }
      }
    cout << "Выберите форму обучения студента:" << "\n" << "1) Очная "
                 "форма." << "\n" << "2) Очно-заочная форма." << "\n"
                 << "3) Заочная форма." << "\n";
    Student->Form=getNumericAnswer (1, 3, "Введите номер желаемого варианта: ");
  }

void dumpListToFile (student *List)
  {
    char fileName[261];
    cout << "\n" << "Введите имя (или путь) файла (по умолчанию - students): ";
    cin.getline (fileName, 261);
    if (fileName[0]=='\0') strcpy(fileName, "students");
    ofstream File;
    File.open (fileName, ios_base::trunc);
    if (File.is_open())
      {
        for (unsigned int i=0; i<listSize; i++)
          {
            student *newStudent;
            newStudent=List+i;
            File << newStudent->Name << "\n";
            File << newStudent->Sex << "\n";
            File << newStudent->Group << "\n";
            File << newStudent->Number << "\n";
            File << newStudent->Ekz1 << "\n";
            File << newStudent->Ekz2 << "\n";
            File << newStudent->Ekz3 << "\n";
            File << newStudent->Diff1 << "\n";
            File << newStudent->Diff2 << "\n";
            File << newStudent->Diff3 << "\n";
            File << newStudent->Diff4 << "\n";
            File << newStudent->Diff5 << "\n";
            File << newStudent->Form << "\n";
            if (i==listSize-1)
              {
                File << newStudent->modificationTime;
              }
            else
              {
                File << newStudent->modificationTime << "\n";
              }
          }
        File.close();
      }
    else
      {
        cout << "Некорректный ввод!" << "\n";
        List=addStudentsFromFile(List);
      }
  }
  
void listFilterChoise (student *List)
  {
    bool answer=getNumericAnswer(1, 2, "\nВыберите желаемый формат списков:\n1)Краткий\n2)Длинный\n\nВведите желаемый вариант: ")-1;
    listFilter(List, answer);
  }  
  
void listFilter (student *List, bool length)
  {
    system (CLEARSCREEN);
    cout << "Вывести список студентов, соответствующих критериям:" << 
                 "\n" << "\n" << "1) Вывести список студентов конкрет"
                 "ной группы." << "\n" << "2) Вывести топ студентов с наив"
                 "ысшим средним баллом за прошедшую сессию." << "\n" << "3"
                 ") Вывод списков студентов мужского и женского полов." <<
                 "\n" << "4) Вывести список студентов, которые будут получ"
                 "ать стипендию по итогам прошедшей сессии." << "\n" << "5"
                 ") Вывести список студентов, которые не будут получают стипенд"
                 "ию." << "\n" << "6) Вывести список студентов, которые уч"
                 "атся только на \"хорошо\" и \"отлично\"." << "\n" << "7)"
                 " Вывести список студентов, которые учатся только на \"отлично"
                 "\"." << "\n" << "8) Выводести список всех студентов, име"
                 "ющих конкретный номер в списке группы." << "\n" << "9) В"
                 "ывод всех записей, сделанных/изменённых в конкретный промежут"
                 "ок времени." << "\n" << "0) Возврат в главное меню." <<
                 "\n" << "\n";
    switch (getNumericAnswer (0, 9, "Введите номер желаемого варианта: "))
      {
        case 1:
          {
            cout << "Введите номер группы: ";
            char Group[11];
            cin.getline(Group, 11);
            listGroup(List, length, Group);
            listFilter(List, length);
            break;
          }
        case 2:
          listTop(List, length);
          listFilter(List, length);
          break;
        case 3:
          listSex(List, length);
          listFilter(List, length);
          break;
        case 4:
          listStipend(List, length);
          listFilter(List, length);
          break;
        case 5:
          listStipendless(List, length);
          listFilter(List, length);
          break;
        case 6:
          listFourFive(List, length);
          listFilter(List, length);
          break;
        case 7:
          listFive(List, length);
          listFilter(List, length);
          break;
        case 8:
          {
            int number=getNumericAnswer(0, 9999, "Введите номер студента в списке группы: ");
            listNumber(List, length, number);
            listFilter(List, length);
            break;
          }
        case 9:
          {
            tm Day=getTmDate();
            int answer=getNumericAnswer(0, 2, "Вывести список записей, сделанных:\n\n0) в течении всего дня.\n1) до полудня.\n2) после полудня.\n\nВведите желаемы вариант: ");
            listTime(List, length, Day, answer);
            listFilter(List, length);
            break;
          }
        default:
          break;
      }
  }
  
void listGroup (student *List, bool length, const char *Group)
  {
    system (CLEARSCREEN);
    cout << "Список студентов в группе " << Group << ":" << "\n" <<
                 "\n";
    int studentNumber=0;
    for (unsigned int i=0; i<listSize; i++)
      {
        if (!strcmp((List+i)->Group, Group))
          {
            if (length)
              {
                printStudentInfo(List, i+1);
                cout << "\n";
              }
            else
              {
                cout << i+1 << ". " << (List+i)->Name << "\n";
              }
            studentNumber++;
          }
      }
    cout << "\n" << "Всего студентов в группе " << Group << ": " <<
                 studentNumber << "." << "\n" << "\n";
    int answer=getNumericAnswer(0, listSize, "Введите номер студента в списке, карточку которого вы хотите посмотреть (для возврата в главное меню введите 0): ");
    if (answer)
      {
        studentMenu (List, answer);
        listGroup (List, length, Group);
      }
  }
  
void listTop (student *List, bool length)
  {
    system (CLEARSCREEN);
    cout << "Топ студентов с наивысшим средним баллом за прошедшую сессию:"
              << "\n" << "\n";
    struct sortList
      {
        unsigned int number;
        double score;
      };
    sortList *SortList=(sortList*)malloc(sizeof(sortList)*listSize);
    for (unsigned int i=0; i<listSize; i++)
      {
        (SortList+i)->number=i;
        (SortList+i)->score=static_cast<float>((((List+i)->Diff1)+((List+i)->Diff2)+((List+i)->Diff3)+((List+i)->Diff4)+((List+i)->Diff5)+((List+i)->Ekz1)+((List+i)->Ekz2)+((List+i)->Ekz3))/8);
      }
    int sorted=0;
    int currentMaxUnsorted=listSize-1;
    while (!sorted)
      {
        sorted=1;
        for (int i=0; i<currentMaxUnsorted; i++)
          {
            if ((SortList+i)->score-(SortList+i+1)->score>0)
              {
                sortList Buffer;
                Buffer.number=(SortList+i)->number;
                Buffer.score=(SortList+i)->score;
                (SortList+i)->number=(SortList+i+1)->number;
                (SortList+i)->score=(SortList+i+1)->score;
                (SortList+i+1)->number=Buffer.number;
                (SortList+i+1)->score=Buffer.score;
                sorted=0;
              }
          }
        currentMaxUnsorted--;
      }
    for (unsigned int i=listSize-1, j=0; i>=0&&j<10; i--, j++)
      {
        if (length)
              {
                printStudentInfo(List, (SortList+i)->number+1);
                cout << "\n";
              }
            else
              {
                cout << ((SortList+i)->number)+1 << ". " <<
                             (List+((SortList+i)->number))->Name << "\n";
              }
      }
    cout << "\n" << "\n";
    int answer=getNumericAnswer(0, listSize, "Введите номер студента в списке, карточку которого вы хотите посмотреть (для возврата в главное меню введите 0): ");
    if (answer)
      {
        studentMenu (List, answer);
        listTop (List, length);
      }
    free(SortList);
  }

void listSex (student *List, bool length)
  {
    system (CLEARSCREEN);
    cout << "Список студентов мужского пола:" << "\n";
    int studentNumber=0;
    for (unsigned int i=0; i<listSize; i++)
      {
        if ((List+i)->Sex==1)
          {
            if (length)
              {
                printStudentInfo(List, i+1);
                cout << "\n";
              }
            else
              {
                cout << i+1 << ". " << (List+i)->Name << "\n";
              }
            studentNumber++;
          }
      }
    cout << "\n" << "Всего студентов мужского пола: " << studentNumber
              << "." << "\n" << "\n" << "Список студентов женского по"
              "ла:" << "\n";
    studentNumber=0;
    for (unsigned int i=0; i<listSize; i++)
      {
        if ((List+i)->Sex==2)
          {
            if (length)
              {
                printStudentInfo(List, i+1);
                cout << "\n";
              }
            else
              {
                cout << i+1 << ". " << (List+i)->Name << "\n";
              }
            studentNumber++;
          }
      }
    cout << "\n" << "Всего студентов женского пола: " << studentNumber
              << "." << "\n" << "\n";
    int answer=getNumericAnswer(0, listSize, "Введите номер студента в списке, карточку которого вы хотите посмотреть (для возврата в главное меню введите 0): ");
    if (answer)
      {
        studentMenu (List, answer);
        listSex (List, length);
      }    
  }

void listStipend (student *List, bool length)
  {
    system (CLEARSCREEN);
    cout << "Список студентов, получающих стипендию:" << "\n" <<
                 "\n";
    int studentNumber=0;
    for (unsigned int i=0; i<listSize; i++)
      {
        if (((((List+i)->Diff1)-3)>0)&&((((List+i)->Diff2)-3)>0)&&((((List+i)->Diff3)-3)>0)&&((((List+i)->Diff4)-3)>0)&&((((List+i)->Diff5)-3)>0)&&((((List+i)->Ekz1)-3)>0)&&((((List+i)->Ekz2)-3)>0)&&((((List+i)->Ekz3)-3)>0)&&((List+i)->Form==1))
          {
            if (length)
              {
                printStudentInfo(List, i+1);
                cout << "\n";
              }
            else
              {
                cout << i+1 << ". " << (List+i)->Name << "\n";
              }
            studentNumber++;
          }
      }
    cout << "\n" << "Всего студентов, получающих стипендию: " <<
                 studentNumber << "." << "\n" << "\n";
    int answer=getNumericAnswer(0, listSize, "Введите номер студента в списке, карточку которого вы хотите посмотреть (для возврата в главное меню введите 0): ");
    if (answer)
      {
        studentMenu (List, answer);
        listStipend (List, length);
      }
  }

void listStipendless (student *List, bool length)
  {
    system (CLEARSCREEN);
    cout << "Список студентов, не получающих стипендию:" << "\n" <<
                 "\n";
    int studentNumber=0;
    for (unsigned int i=0; i<listSize; i++)
      {
        if (((((List+i)->Diff1)-3)<=0)||((((List+i)->Diff2)-3)<=0)||((((List+i)->Diff3)-3)<=0)||((((List+i)->Diff4)-3)<=0)||((((List+i)->Diff5)-3)<=0)||((((List+i)->Ekz1)-3)<=0)||((((List+i)->Ekz2)-3)<=0)||((((List+i)->Ekz3)-3)<=0)||(!((List+i)->Form==1)))
          {
            if (length)
              {
                printStudentInfo(List, i+1);
                cout << "\n";
              }
            else
              {
                cout << i+1 << ". " << (List+i)->Name << "\n";
              }
            studentNumber++;
          }
      }
    cout << "\n" << "Всего студентов, не получающих стипендию: " <<
                 studentNumber << "." << "\n" << "\n";
    int answer=getNumericAnswer(0, listSize, "Введите номер студента в списке, карточку которого вы хотите посмотреть (для возврата в главное меню введите 0): ");
    if (answer)
      {
        studentMenu (List, answer);
        listStipendless (List, length);
      }
  }

void listFourFive (student *List, bool length)
  {
    system (CLEARSCREEN);
    cout << "Список студентов, которые учатся только на \"хорошо\" и \"отл"
                 "ично\":" << "\n" << "\n";
    int studentNumber=0;
    for (unsigned int i=0; i<listSize; i++)
      {
        if (((((List+i)->Diff1)-3)>0)&&((((List+i)->Diff2)-3)>0)&&((((List+i)->Diff3)-3)>0)&&((((List+i)->Diff4)-3)>0)&&((((List+i)->Diff5)-3)>0)&&((((List+i)->Ekz1)-3)>0)&&((((List+i)->Ekz2)-3)>0)&&((((List+i)->Ekz3)-3)>0))
          {
            if (length)
              {
                printStudentInfo(List, i+1);
                cout << "\n";
              }
            else
              {
                cout << i+1 << ". " << (List+i)->Name << "\n";
              }
            studentNumber++;
          }
      }
    cout << "\n" << "Всего студентов, которые учатся только на \"хоро"
                 "шо\" и \"отлично\": " << studentNumber << "." << "\n" <<
                 "\n";
    int answer=getNumericAnswer(0, listSize, "Введите номер студента в списке, карточку которого вы хотите посмотреть (для возврата в главное меню введите 0): ");
    if (answer)
      {
        studentMenu (List, answer);
        listFourFive (List, length);
      }
  }

void listFive (student *List, bool length)
  {
    system (CLEARSCREEN);
    cout << "Список студентов, которые учатся только на \"отлично\":" <<
                 "\n" << "\n";
    int studentNumber=0;
    for (unsigned int i=0; i<listSize; i++)
      {
        if (((((List+i)->Diff1)-4)>0)&&((((List+i)->Diff2)-4)>0)&&((((List+i)->Diff3)-4)>0)&&((((List+i)->Diff4)-4)>0)&&((((List+i)->Diff5)-4)>0)&&((((List+i)->Ekz1)-4)>0)&&((((List+i)->Ekz2)-4)>0)&&((((List+i)->Ekz3)-4)>0))
          {
            if (length)
              {
                printStudentInfo(List, i+1);
                cout << "\n";
              }
            else
              {
                cout << i+1 << ". " << (List+i)->Name << "\n";
              }
            studentNumber++;
          }
      }
    cout << "\n" << "Всего студентов, которые учатся только на \"отли"
                 "чно\": " << studentNumber << "." << "\n" << "\n";
    int answer=getNumericAnswer(0, listSize, "Введите номер студента в списке, карточку которого вы хотите посмотреть (для возврата в главное меню введите 0): ");
    if (answer)
      {
        studentMenu (List, answer);
        listFive (List, length);
      }
  }

void listNumber (student *List, bool length, int Number)
  {
    system (CLEARSCREEN);
    cout << "Список студентов, имеющих номер " << Number << " в списке гру"
                 "ппы:" << "\n" << "\n";
    int studentNumber=0;
    for (unsigned int i=0; i<listSize; i++)
      {
        if ((List+i)->Number==Number)
          {
            if (length)
              {
                printStudentInfo(List, i+1);
                cout << "\n";
              }
            else
              {
                cout << i+1 << ". " << (List+i)->Name << "\n";
              }
            studentNumber++;
          }
      }
    cout << "\n" << "Всего студентов, имеющих номер " << Number <<
                " в списке группы: " << studentNumber << "." << "\n" <<
                "\n";
    int answer=getNumericAnswer(0, listSize, "Введите номер студента в списке, карточку которого вы хотите посмотреть (для возврата в главное меню введите 0): ");
    if (answer)
      {
        studentMenu (List, answer);
        listNumber (List, length, Number);
      }
  }

void listTime (student *List, bool length, tm Begin, int Noon)
  {
    system (CLEARSCREEN);
    cout << "Список студентов, записи о которых сделаны в указанный промеж"
                 "уток времени:" << "\n" << "\n";
    tm End;
    End.tm_sec=Begin.tm_sec;
    End.tm_min=Begin.tm_min;
    End.tm_hour=Begin.tm_hour;
    End.tm_mday=Begin.tm_mday;
    End.tm_mon=Begin.tm_mon;
    End.tm_year=Begin.tm_year;
    End.tm_isdst=Begin.tm_isdst;
    switch (Noon)
      {
        case 0:
          End.tm_sec=59;
          End.tm_min=59;
          End.tm_hour=23;
          break;
        case 1:
          End.tm_sec=59;
          End.tm_min=59;
          End.tm_hour=11;
          break;
        case 2:
          End.tm_sec=59;
          End.tm_min=59;
          End.tm_hour=23;
          Begin.tm_sec=00;
          Begin.tm_min=00;
          Begin.tm_hour=12;
          break;
      }
    time_t beginTime=mktime(&Begin);
    time_t endTime=mktime(&End);
    int studentNumber=0;
    for (unsigned int i=0; i<listSize; i++)
      {
        if ((((List+i)->modificationTime)>=beginTime)&&(((List+i)->modificationTime)<=endTime))
          {
            if (length)
              {
                printStudentInfo(List, i+1);
                cout << "\n";
              }
            else
              {
                cout << i+1 << ". " << (List+i)->Name << "\n";
              }
            studentNumber++;
          }
      }
    cout << "\n" << "Всего студентов, записи о которых сделаны в указ"
                 "анный промежуток времени: " << studentNumber << "." <<
                 "\n" << "\n";
    int answer=getNumericAnswer(0, listSize, "Введите номер студента в списке, карточку которого вы хотите посмотреть (для возврата в главное меню введите 0): ");
    if (answer)
      {
        studentMenu (List, answer);
        listTime (List, length, Begin, Noon);
      }
  }

tm getTmDate ()
  {
    tm Day;
    cout << "Введите дату (формат: ДД.ММ.ГГГГ): ";
    char date[11];
    cin.getline(date, 11);
    Day.tm_sec=0;
    Day.tm_min=0;
    Day.tm_hour=0;
    Day.tm_mday=(date[0]-48)*10+(date[1]-48);
    Day.tm_mon=(date[3]-48)*10+(date[4]-48)-1;
    Day.tm_year=(date[6]-48)*1000+(date[7]-48)*100+(date[8]-48)*10+(date[9]-48)-1900;
    Day.tm_isdst=-1;
    if (mktime(&Day)<0)
      {
        cout << "Некорректный ввод!" << "\n";
        Day=getTmDate();
      }
    return Day;
  }
