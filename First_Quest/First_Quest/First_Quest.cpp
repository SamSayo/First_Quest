#include <iostream>
#include <string>
#include <Windows.h>
#include <tchar.h>
#include <conio.h>
#include <strsafe.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

//Функции игры

//Меню
void menu(); 
//Основная часть игры
void mainGame(); 
//Боевой режим
void battleMode(int mob, int health, int mobLevel);
//Ходьба
void freeRoam();

//Технические функции

//Перекидывать строку на x и y координаты (120 в ширину(x) и 40 в высоту(y))
void gotoxy(int x, int y); 
//Задание цвета текста
void setcolor(int color); 
//Отрисовка диалогового окна
void dialogue(); 
//Выключение курсора
void hideCursor(); 
//Включение курсора
void showCursor(); 
//Настройка
void resolutionWaiting();
//Загрузка
void loading();
//Вывод логотипа
void printLogo();
//Вывод титров
void titles();
//Starting NE-DDOS...
void nedos();


void slimeOut();



enum class weapons
{
    sword = 1,
    magic_dagger, // магический кинжал
    axe, // топор
    mace, //булава
    battle_axe, // боевой топор
    Mace, // палица
    ax, //секира
    th_sword, // двуручный молот 
    throwing_knife, // метательный нож
    throwing_axe, // метательный топор
    morgenstern, // моргенштерн - все твои родные богатые и здоровые, и с***ался
    spear, // копье 
    epee, // шпага
    trident, // трезубец
    peak, // пика те че НААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААААА
    harpoon, // гарпуун
    saber, // шпага т
    bow, // лук 50 рублей за килограм
    crossbow, // арбалет
};
enum class arrows_bolts //стрелы и болты
{
    arrow = 1, // стрела - когда то я тоже был великим искателем приключений но потом мне прострелили колено.
    bolt, // болт
};
enum class armor //броня
{
    helmet = 1, // шлем
    armor, // доспех
    bracers, // наручи - наруууууутоооооооооооооооооооооооо
    gloves, // перчаточки - lets selebrate and suck some dick!!!!!!!!!!
    leggings, // поножи - ножки да рожки
    boots1_boots2, // сапоги и ботинки
    shield, // щит - буууул щииииииит
};
enum class magicweapon //магическое оружие
{
    staff = 1, // магический посох
    magic_vand, // магическая палочка - сосалочка
    book_spell, // учебник по химии 
};
enum class magicaccessory //магические аксессуары
{
    medallion = 1, // медальён бульен
    bracelet, // браслет - говна ответ
    ring, // анальное кольцо
    onyx, // оникс очконис
    tiara, // тиара гачара
    hoop, // обруч оч ноуч
    necklace, // ожерелье форелье
};
enum class mobs
{
    skeleton = 1,
    zombie,
    demon,
    slime,
    spider,
    frog,
    chimera,
    hog,
    crab,
    overCrab,
    wolf,
    dryad,
    gnome,
    dwarf,
    ent,
    ogre,
    mimic,
    dragonite,
    lizardMan,
    overSpider,
    werewolf,
    queenBee,
    cyclops,
    siren,
    dragon
};
enum class food
{
    potato = 1,
    bakedPotato,
    carrot,
    apple,
    bakedChicken,
    pork,
    steak,
    chickenSoup,
    beefSoup,
    eggplant,
    tomato,
    cucumber, //ХАХАХАХАХА, КУКМБЕР
    smallCheese,
    cheese,
    aegeanCheese,
    bigCheese,
    sausage,
    smokeSausage,
    rawSmokeSausage,
    balyk,
    ham,
    turkey,
    curd,
    cabbage,
    salt,
    sugar,
    pepper,
    cauliflower,
    milk1L,
    milk5L,
    milk10L,
    egg,
    sourCream,
    friedEgg,
    waffles,
    water,
    juice,
    wine,
    cognac,
    brandy,
    beer,
    mushroom,
    lightMushroom,
    sloak,
    shoark,
    pargs,
    shirgs,
    mango,
    radish,
    peanut,
    cashews,
    pineapple,
    passionFruit,
    celery,
    walnut,
    cherry,
    currant
};
enum class regenPotions
{
    smallRegen = 1,
    usualRegen,
    regen,
    hiqyRegen,
    excelRegen
};

//Цвета
const int Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4,
    Magneta = 5, Brown = 6, LGray = 7, DGray = 8,
    LBlue = 9, LGreen = 10, LCyan = 11, LRed = 12,
    LMagneta = 13, Yellow = 14, White = 15;

struct character
{
    int level = 1;
    int hp = 100;
    int sp = 0;
    /*int xp = 0;
    float progress = 0;*/
};

string name;

int main()
{
    setlocale(LC_ALL, "");
    hideCursor();
    srand(time(NULL));
    
    TCHAR szOldTitle[MAX_PATH];
    TCHAR szNewTitle[MAX_PATH];

    // Save current console title.
    if (GetConsoleTitle(szOldTitle, MAX_PATH))
    {
        // Build new console title string.

        StringCchPrintf(szNewTitle, MAX_PATH, TEXT("Желание Судьбы"), szOldTitle);

        // Set console title to new title
        if (!SetConsoleTitle(szNewTitle))
        {
            _tprintf(TEXT("SetConsoleTitle failed (%d)\n"), GetLastError());
            return 1;
        }
        else
        {
            nedos();
            resolutionWaiting();
            loading();
            printLogo();
        }
    }
    
    menu();
    Sleep(150);
    gotoxy(23, 18);
    system("pause");
    system("cls");
    
    for (int i = 1; i < 7; i++)
    {
        gotoxy(54, 13);
        setcolor(i);
        cout << "Хорошей игры" << endl;
        Sleep(500);
        system("cls");
    }
    loading();
    mainGame();
    titles();
}

void menu()
{
    setcolor(Yellow); //Смена цветa
    //Слово желание
    //Первая строка
    gotoxy(23, 6);
    cout << "###  ##  ###   #####       ##           ##      ##    ##   #    ##   #####" << endl;
    //Вторая строка
    gotoxy(23, 7);
    cout << " ### ## ###    ##         ####         ####     ##    ##   #   # #   ##" << endl;
    //Третья строка
    gotoxy(23, 8);
    cout << "   #####       ####      ##  ##       ##  ##    ########   #  #  #   ###" << endl;
    //Четвёртая строка
    gotoxy(23, 9);
    cout << " ### ## ###    ##       ##    ##     ########   ##    ##   # #   #   ##" << endl;
    //Пятая строка
    gotoxy(23, 10);
    cout << "###  ##  ###   #####   ##      ##   ##      ##  ##    ##   ##    #   #####" << endl;

    cout << endl;

    //Слово судьбы
    //Первая строка
    gotoxy(23, 12);
    cout << "######   ###   ###   ##       ##       ######  ##     ##" << endl;
    //Вторая строка
    gotoxy(23, 13);
    cout << "##        ### ###   ####      ##       ##      ##     ##" << endl;
    //Третья строка
    gotoxy(23, 14);
    cout << "##         #####   ##  ##     ####     ####    ####   ##" << endl;
    //Четвёртая строка
    gotoxy(23, 15);
    cout << "##          ###   ##    ##    ##  ##   ##  ##  ##  ## ##" << endl;
    //Пятая строка
    gotoxy(23, 16);
    cout << "######      ##   ##########   ######   ######  ###### ##" << endl;

    /*cout << endl << "Press the 1 button on the keyboard to start" << endl;

    while (enter != 1)
    {
        cin >> enter;
        if (enter > 1)
            cout << "Not " << enter << ", but 1" << endl;
    }*/
    cout << endl;
    //gotoxy(23, 18);
    //system("pause");
}

void mainGame()
{  
    //Доп. инфа
    //сначала отчищать экран system("cls");
    //Потом использовать функцию окна
    dialogue();
    gotoxy(3, 2); //Начало строки с отступом
    setcolor(Cyan);
    cout << "-..." << endl;
    Sleep(1500);
    gotoxy(3, 3);
    cout << "-....." << endl;
    Sleep(2000);
    gotoxy(3, 4);
    cout << "-Темнота... ";
    Sleep(2000);
    cout << "Где я?... ";
    Sleep(2000);
    cout << "Я не чувствую тела...";
    Sleep(2000);
    cout << "Видимо я умер... ";
    Sleep(2000);
    cout << "Ну что-же видимо настал и мой конец... ";
    Sleep(3000);
    gotoxy(4, 5);
    cout << "Это хорошая была жизнь..." << endl;
    Sleep(3500);
    gotoxy(3, 12);
    system("pause");//Вывод сообщения нажмите любую кнопку для продолжение

    system("cls");
    dialogue();
    setcolor(Red);
    gotoxy(3, 2);
    cout << "-Проснись!" << endl;
    Sleep(2000); //Остановка на N миллисекунд

    setcolor(Cyan);
    gotoxy(3, 3);
    cout << "-Чего?" << endl;
    Sleep(2000);

    setcolor(Red);
    gotoxy(3, 4);
    cout << "-ПРОСНИСЬ!" << endl;
    Sleep(2000);

    setcolor(White);
    gotoxy(3, 6);
    cout << "*Вы открываете глаза. Из-за резкого света вас ослепило. ";
    gotoxy(4, 7);
    cout << "Вы решили ещё полежать.*" << endl;
    gotoxy(3, 12);
    system("pause");
    system("cls");

    
    dialogue();
    setcolor(Red);
    gotoxy(3, 2);
    cout << "-ПРОСЫПАЙСЯ!!" << endl;
    Sleep(2000);

    setcolor(White);
    gotoxy(3, 5);
    cout << "*Вы резко встаёте и видите около себя старого деда, ";
    gotoxy(3, 6); 
    cout << "с вилами в руках готовый при любом раскладе вонзить их в вас*" << endl;
    gotoxy(3, 12);
    system("pause");
    system("cls");

    
    dialogue();
    setcolor(Red);
    gotoxy(3, 2);
    cout << "-О, наконец, проснулся оборванец" << endl;
    Sleep(2500);

    setcolor(Cyan);
    gotoxy(3, 3);
    cout << "-Где я?" << endl;
    Sleep(2000);

    setcolor(Red);
    gotoxy(3, 4);
    cout << "-Ты идиот? Ты значит упал с неба, "; 
    Sleep(2000);
    cout << "сломал мне крышу, ";
    Sleep(2000);
    cout << "придавил собой мою лошадь "; 
    Sleep(2000);
    cout << "и потом ещё спрашиваешь где ты" << endl;
    Sleep(2000);
    
    setcolor(Cyan);
    gotoxy(3, 5);
    cout << "-Я ничего не помню..." << endl;
    Sleep(2000);
    gotoxy(3, 12);
    system("pause");
    system("cls");

    dialogue();
    setcolor(Red);
    gotoxy(3, 2);
    cout << "-После запоя что-ли?... ";
    Sleep(1500);
    cout << "Ладно, как тебя звать то? " << endl;
    Sleep(2000);

    setcolor(Cyan);
    gotoxy(3, 3);
    cout << "-Меня зовут ";
    showCursor();
    cin >> name;
    hideCursor();
    Sleep(2000);

    setcolor(Red);
    gotoxy(3, 4);
    cout << "-Хм.. "; Sleep(1000);
    cout << name; Sleep(1500);
    cout << " попытаюсь запомнить" << endl;
    gotoxy(3, 12);
    system("pause");
    system("cls");

    dialogue();
    setcolor(Cyan);
    gotoxy(3, 2);
    cout << "-Итак, старик, где я?"; Sleep(2000); cout << " Что это за место?" << endl;
    Sleep(3000);

    setcolor(Red);
    gotoxy(3, 3);
    cout << "-Сейчас мы находимся у меня на ферме, "; Sleep(1500); cout << "а так мы в королевстве Джирсал под управлением его величества Ролдера Фолла" << endl;
    gotoxy(3, 12);
    system("pause");
    cout << endl;

    setcolor(LCyan);
    gotoxy(3, 4);
    cout << "\"Возможно король знает как выбраться от сюда..."; Sleep(1500); cout << "Мне надо его допросить\"" << endl;
    gotoxy(3, 12);
    system("pause");
    system("cls");

    dialogue();
    setcolor(Cyan);
    gotoxy(3, 2);
    cout << "-Как я могу попасть к нему?" << endl;
    gotoxy(3, 12);
    system("pause");


}

void battleMode(int mob, int health, int mobLevel)
{
    
    switch (mob)
    {
    case 4:
        int mobHp = 15;
        while (true)
        {
            system("cls");
            gotoxy(3, 2);
            cout << "Слайм\tУровень: " << mobLevel;
            slimeOut();
            
            
        }
        
        break;
    }
}

void freeRoam()
{
    for (int i = 0; i < 30; i++)
    {
        cout << "########################################################################################################################" << endl;
    }
}

void dialogue()
{
    setcolor(White);
    cout << "########################################################################################################################" << endl;
    for (int i = 0; i < 13; i++)
    {
        cout << "#                                                                                                                      #" << endl;
    }
    cout << "########################################################################################################################" << endl;
}

void hideCursor()
{
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hConsoleHandle, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsoleHandle, &structCursorInfo);

}

void showCursor()
{
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hConsoleHandle, &structCursorInfo);
    structCursorInfo.bVisible = TRUE;
    SetConsoleCursorInfo(hConsoleHandle, &structCursorInfo);

}

void resolutionWaiting()
{
    setcolor(White);
    cout << "Время настроки!" << endl;
    cout << endl << "Откройте настройки командной строки, щелкнув правой кнопкой мыши по значку в левом верхнем углу." << endl << "Далее нажмите на кнопку \"Свойства\", затем откройте вкладку \"Расположение\" и " << endl << "установите ширину равной 120, а высоту равной 40 в окне \"Размер окна\"." << endl;
    cout << endl << "Готово?" << endl;
    system("pause");
    system("cls");
}

void slimeOut()
{
    dialogue();
    //Первая строка
    gotoxy(42, 16);
    cout << "            *****" << endl;

    //Вторая строка
    gotoxy(42, 17);
    cout << "           **__***" << endl;

    //Третья строка
    gotoxy(42, 18);
    cout << "          *********" << endl;

    //Четвёртвая строка
    gotoxy(42, 19);
    cout << "         ***********" << endl;

    //Пятая строка
    gotoxy(42, 20);
    cout << "        ****__*******" << endl;

    //Шестая строка
    gotoxy(42, 21);
    cout << "       ***************" << endl;

    //Седьмая строка
    gotoxy(42, 22);
    cout << "      ***********__****" << endl;

    //Восьмая строка
    gotoxy(42, 23);
    cout << "     *******************" << endl;

    //Девятая строка
    gotoxy(42, 24);
    cout << "    *******__************" << endl;

    //Десятая строка
    gotoxy(42, 25);
    cout << "   ***************__******" << endl;
    
    //Одиннадцатая строка
    gotoxy(42, 26);
    cout << "  ****__*******************" << endl;
    
    //Двенадцатая строка
    gotoxy(42, 27);
    cout << " ***************************" << endl;
    
    //Тринадцатая строка
    gotoxy(42, 28);
    cout << "*****************************" << endl;

    //gotoxy(3, 12);
    //system("pause");
}

void printLogo()
{
    setcolor(DGray);
    gotoxy(85, 7);
    cout << "Компашка" << endl;
    gotoxy(60, 19);
    cout << "Представляют" << endl;
    gotoxy(28, 9);
    cout << "      #####      #####        ##      ##       ###   #########" << endl;
    gotoxy(28, 10);
    cout << "     #    #     #     #      ####     ##      # ##   ##     ##" << endl;
    gotoxy(28, 11);
    cout << "    #     #    #       #    # ## #    ##     #  ##   ##" << endl;
    gotoxy(28, 12);
    cout << "   #      #    #########   #  ##  #   ##    #   ##   ##" << endl;
    gotoxy(28, 13);
    cout << "  #       #    #           #  ##  #   ##   #    ##   ##" << endl;
    gotoxy(28, 14);
    cout << " ###########   #            # ## #    ##  #     ##   ##" << endl;
    gotoxy(28, 15);
    cout << " #         #    #      #     ####     ## #      ##   ##     ##" << endl;
    gotoxy(28, 16);
    cout << "  #       #      ######       ##      ###       ##   #########" << endl;
    Sleep(250);

    setcolor(LGray);
    gotoxy(85, 7);
    cout << "Компашка" << endl;
    gotoxy(60, 19);
    cout << "Представляют" << endl;
    gotoxy(28, 9);
    cout << "      #####      #####        ##      ##       ###   #########" << endl;
    gotoxy(28, 10);
    cout << "     #    #     #     #      ####     ##      # ##   ##     ##" << endl;
    gotoxy(28, 11);
    cout << "    #     #    #       #    # ## #    ##     #  ##   ##" << endl;
    gotoxy(28, 12);
    cout << "   #      #    #########   #  ##  #   ##    #   ##   ##" << endl;
    gotoxy(28, 13);
    cout << "  #       #    #           #  ##  #   ##   #    ##   ##" << endl;
    gotoxy(28, 14);
    cout << " ###########   #            # ## #    ##  #     ##   ##" << endl;
    gotoxy(28, 15);
    cout << " #         #    #      #     ####     ## #      ##   ##     ##" << endl;
    gotoxy(28, 16);
    cout << "  #       #      ######       ##      ###       ##   #########" << endl;
    Sleep(250);

    setcolor(White);
    gotoxy(85, 7);
    cout << "Компашка" << endl;
    gotoxy(60, 19);
    cout << "Представляют" << endl;
    gotoxy(28, 9);
    cout << "      #####      #####        ##      ##       ###   #########" << endl;
    gotoxy(28, 10);
    cout << "     #    #     #     #      ####     ##      # ##   ##     ##" << endl;
    gotoxy(28, 11);
    cout << "    #     #    #       #    # ## #    ##     #  ##   ##" << endl;
    gotoxy(28, 12);
    cout << "   #      #    #########   #  ##  #   ##    #   ##   ##" << endl;
    gotoxy(28, 13);
    cout << "  #       #    #           #  ##  #   ##   #    ##   ##" << endl;
    gotoxy(28, 14);
    cout << " ###########   #            # ## #    ##  #     ##   ##" << endl;
    gotoxy(28, 15);
    cout << " #         #    #      #     ####     ## #      ##   ##     ##" << endl;
    gotoxy(28, 16);
    cout << "  #       #      ######       ##      ###       ##   #########" << endl;
    Sleep(1000);

    setcolor(LGray);
    gotoxy(85, 7);
    cout << "Компашка" << endl;
    gotoxy(60, 19);
    cout << "Представляют" << endl;
    gotoxy(28, 9);
    cout << "      #####      #####        ##      ##       ###   #########" << endl;
    gotoxy(28, 10);
    cout << "     #    #     #     #      ####     ##      # ##   ##     ##" << endl;
    gotoxy(28, 11);
    cout << "    #     #    #       #    # ## #    ##     #  ##   ##" << endl;
    gotoxy(28, 12);
    cout << "   #      #    #########   #  ##  #   ##    #   ##   ##" << endl;
    gotoxy(28, 13);
    cout << "  #       #    #           #  ##  #   ##   #    ##   ##" << endl;
    gotoxy(28, 14);
    cout << " ###########   #            # ## #    ##  #     ##   ##" << endl;
    gotoxy(28, 15);
    cout << " #         #    #      #     ####     ## #      ##   ##     ##" << endl;
    gotoxy(28, 16);
    cout << "  #       #      ######       ##      ###       ##   #########" << endl;
    Sleep(250);

    setcolor(DGray);
    gotoxy(85, 7);
    cout << "Компашка" << endl;
    gotoxy(60, 19);
    cout << "Представляют" << endl;
    gotoxy(28, 9);
    cout << "      #####      #####        ##      ##       ###   #########" << endl;
    gotoxy(28, 10);
    cout << "     #    #     #     #      ####     ##      # ##   ##     ##" << endl;
    gotoxy(28, 11);
    cout << "    #     #    #       #    # ## #    ##     #  ##   ##" << endl;
    gotoxy(28, 12);
    cout << "   #      #    #########   #  ##  #   ##    #   ##   ##" << endl;
    gotoxy(28, 13);
    cout << "  #       #    #           #  ##  #   ##   #    ##   ##" << endl;
    gotoxy(28, 14);
    cout << " ###########   #            # ## #    ##  #     ##   ##" << endl;
    gotoxy(28, 15);
    cout << " #         #    #      #     ####     ## #      ##   ##     ##" << endl;
    gotoxy(28, 16);
    cout << "  #       #      ######       ##      ###       ##   #########" << endl;
    Sleep(250);

    setcolor(Black);
    gotoxy(85, 7);
    cout << "Компашка" << endl;
    gotoxy(60, 19);
    cout << "Представляют" << endl;
    gotoxy(28, 9);
    cout << "      #####      #####        ##      ##       ###   #########" << endl;
    gotoxy(28, 10);
    cout << "     #    #     #     #      ####     ##      # ##   ##     ##" << endl;
    gotoxy(28, 11);
    cout << "    #     #    #       #    # ## #    ##     #  ##   ##" << endl;
    gotoxy(28, 12);
    cout << "   #      #    #########   #  ##  #   ##    #   ##   ##" << endl;
    gotoxy(28, 13);
    cout << "  #       #    #           #  ##  #   ##   #    ##   ##" << endl;
    gotoxy(28, 14);
    cout << " ###########   #            # ## #    ##  #     ##   ##" << endl;
    gotoxy(28, 15);
    cout << " #         #    #      #     ####     ## #      ##   ##     ##" << endl;
    gotoxy(28, 16);
    cout << "  #       #      ######       ##      ###       ##   #########" << endl;
    Sleep(250);

    system("cls");
}

void titles()
{
    setcolor(White);
    system("cls");
    
    gotoxy(45, 13);
    cout << "Конец демонстрационной версии" << endl;
    Sleep(5000);

    ssystem("cls");
    gotoxy(45, 13);
    cout << "Программирование и ";
    setcolor(Cyan);
    cout << "г";
    setcolor(Magneta);
    cout << "р";
    setcolor(Red);
    cout << "а";
    setcolor(Green);
    cout << "ф";
    setcolor(Blue);
    cout << "и";
    setcolor(Brown);
    cout << "к";
    setcolor(White);
    cout << "а: " << endl;
    Sleep(2000);
    gotoxy(43, 15);
    cout << "Дмитрий \"samSayonara();\" Романов" << endl;
    Sleep(2000);
    setcolor(Black);
    system("pause");

    system("cls");
    setcolor(White);
    gotoxy(53, 13);
    cout << "Геймдизайн: " << endl;
    Sleep(2000);
    gotoxy(51, 15);
    cout << "Фёдор Поздняков" << endl;
    Sleep(2000);

    setcolor(Black);
    system("pause");
    setcolor(White);
    system("cls");
}

void nedos()
{
    long int command = 0;
    system("cls");
    hideCursor();

    cout << "Запускается NE-DDOS...." << endl << endl << endl;
    Sleep(2000);
    cout << "LOMEM is nothing testing in extended memory....undone" << endl << endl;
    Sleep(2000);
    cout << "B:\\>B:\\DDOS\\STUPIDDRIVE.BAT /Z" << endl;
    Sleep(1000);
    cout << "B:\\>B:\\GAME\\INSTRUCTION.TXT" << endl ;
    cout << "Чтобы запустить игру, введите число 1 \nЧтобы выключить NE-DDOS, введите 2" << endl;

    while (command != 9999)
    {
        cout << "B:\>";
        showCursor();
        cin >> command;
        hideCursor();

        switch (command)
        {
        case 1:
            command = 9999;
            break;
        case 2:
            system("cls");
            exit(1991);

            break;
        default:
            cout << "Ддос не знает такую команду" << endl;
            break;
        }
    }
    system("cls");
}

void loading()
{
    for (int i = 0; i < 3; i++)
    {
        gotoxy(107, 40);
        setcolor(Black);
        _tprintf(TEXT("Загрузка...\n"));
        gotoxy(119, 40);
        setcolor(White);
        cout << "-";
        Sleep(150);

        gotoxy(107, 40);
        setcolor(DGray);
        _tprintf(TEXT("Загрузка...\n"));
        gotoxy(119, 40);
        setcolor(White);
        cout << "\\";
        Sleep(150);

        gotoxy(107, 40);
        setcolor(LGray);
        _tprintf(TEXT("Загрузка...\n"));
        gotoxy(119, 40);
        setcolor(White);
        cout << "|";
        Sleep(150);

        gotoxy(107, 40);
        setcolor(White);
        _tprintf(TEXT("Загрузка...\n"));
        gotoxy(119, 40);
        cout << "/";
        Sleep(150);

        gotoxy(107, 40);
        setcolor(LGray);
        _tprintf(TEXT("Загрузка...\n"));
        gotoxy(119, 40);
        setcolor(White);
        cout << "-";
        Sleep(150);

        gotoxy(107, 40);
        setcolor(DGray);
        _tprintf(TEXT("Загрузка...\n"));
        gotoxy(119, 40);
        setcolor(White);
        cout << "|";
        Sleep(150);

        gotoxy(107, 40);
        setcolor(Black);
        _tprintf(TEXT("Загрузка...\n"));
        gotoxy(119, 40);
        setcolor(White);
        cout << "/";
        Sleep(150);
        system("cls");
    }
}

void gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(hConsoleHandle, pos);
}

void setcolor(int color)
{
    SetConsoleTextAttribute(hConsoleHandle, color);
}
