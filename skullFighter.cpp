#include <iostream>
#include <fstream>   // File input/output for save/load features
#include <windows.h> // Windows console control (cursor, colors)
#include <conio.h>   // Keyboard input (getch)
#include <limits>    // Input buffer handling
#include <iomanip>   // Output formatting (setw)
using namespace std;

int level1();
//------for game formtting------
void maze();
void header();
string menu();
void drawMazeBorder(int width);
void drawMazeWalls(int width);
void printCoin(int x, int y);
void printDoor(int x, int y);
void printTree(int x, int y);
void printHeart(int x, int y);
void drawLevel();
void drawFire(int x, int y);
void gotoxy(int x, int y);
void hideCursor();
void gameOver();
void youWin();
int handlePause();
void points(int score);
void playerHealth(int health);
char getCharAtxy(short int x, short int y);

// ======================================
// functions for player for movement or fire...
void player(int &px, int &py);
void playerErase(int &px, int &py);
void playerMove(int &playerXCo, int &playerYCo, int &score, int &health);
void createBullet(int x, int y, string direction);
void printBullet(int x, int y);
void eraseBullet(int x, int y);
void moveBullet(int skullXCoordinate[], int &score, int skullHealth[]);
void smartEraseLogic(int x, int y, int playerX, int playerY);

// =======================================
// functions for enemies movment,fires...
void skull(int &ex, int &ey);
void eraseSkull(int &eX, int &eY, int px, int py);
void createBulletForSull(int x, int y);
void printBulletForEnemy(int x, int y);
void eraseBulletEnemy(int x, int y);
void moveBulletenemy();
void moveBulletRightEnemy();
void createBulletForSull3Right(int x, int y);
void moveBulletLeftEnemy();
void createBulletForSull4Left(int x, int y);
void leftToRight(int skullXCoordinate[], int skullYCoordinate[], string direction[]);

// ==========================================
void movefireBombDown(int &health);
void createFireBomb(int x, int y);
void movefireBombUp(int &health);
void createFireBombUp(int x, int y);
void erasefireBomb(int x, int y);
void printFireBomb(int x, int y);

// ==========================================
// these functions are for collions detects or reduce points
void fireFromEnemyDetect(int px, int py, int &health);
void checkCollisions(int &px, int &py, int &health);
void generateEnemyAttacks(int sX[], int sY[], int fireX, int fireY, int timer, int skullHealth[]);

// ==============================================
void level2();
void level2Instructions();
void drawLevel1();
void briks(int x, int y);
void briks1(int x, int y);
void drawSpikes(int x, int y, bool active);
void drawSpider(int x, int y);
void moveSpider(int spiderXCo[], string spiderDirection[]);
void drawMech(int x, int y);
void printPrison(int x, int y);
void drawBossSpider(int x, int y);
void eraseBossSpider(int x, int y, int px, int py);
void moveBossSpider(int &bX, string &bossSpiderDirection);
void eraseEnemy(int spiderX[], int spiderY[], int bossSpiderX, int bossSpiderY, int bossHealth, int spiderHealth[], int playerX, int playerY);
void eraseInMove(int x, int y);
void moveMech(int mechXCo[], int mechYCo[], string directionMech[]);
void eraseSpider(int x, int y, int px, int py);
void eraseMech(int mechXCoordinate[], int mechYCoordinate[], int mechHealth[], int playerX, int playerY);
void moveBulletBossSpiderRight();
void eraseBombForBoss(int &x, int &y);
void printBombForBoss(int &x, int &y);
void createBulletForBossSpider(int x, int y);
void createBulletForBossSpiderLeft(int x, int y);
void moveBulletBossSpiderLeft();
void generateEnemyAttach(int spiderHealth[], int sX[], int sY[], int timer, int bX, int bY, int &bossHealth);
void specialWeaponAndFire(int playerLevel2XCoordinate, int playerLevel2YCoordinate, int &score);
void moveBulletLevel2(int mechXCoordinate[], int mechYCoordinate[], int &score, int mechHealth[], int spiderX[], int spiderHealth[], int bossSpiderX, int &bossHealth);

// function to store score namd names
void showLeaderBoard();
void fileSave(string fileName, string name, int score);
int find_max(int index, int doneScore[], int idx);
void sortPlayersDescending(string name[], int doneScore[], int idx);

// arays for automatic firebomb down
int fireBombDownX[100], fireBombDownY[100], fireBombDownCount = 0;
// arays for automatic firebomb up
int fireBombUpX[100], fireBombUpY[100], fireBombUpCount = 0;
// arrays to detect player fires
int bulletX[100], bulletY[100], bulletCount = 0;
// arrays for enemies to produce fires
int enemyBulletX[100], enemyBulletY[100], enemyBulletCount = 0;
// array for enemy to fire right
int bulletRightX[100], bulletRightY[100], bulletCountRight = 0;
// array for enemy to fire left
int bulletLeftX[100], bulletLeftY[100], bulletCountLeft = 0;

//----------arrays for boss enemy for fire--------
int bossSpiderRightBulletX[100], bossSpiderRightBulletY[100], bossBulletCountRight = 0;
int bossSpiderLeftBulletX[100], bossSpiderLeftBulletY[100], bossBulletCountLeft = 0;
string bulletDirection[100];
bool hasSpecialWeapon = false;
int health = 100, score = 0;

// strating of main function
int main()
{
    system("cls");
    hideCursor();
    maze();

    string name = menu();

    cout << "\a";
    system("cls");
    gotoxy(0, 0);
    maze();
    int health;
    health = level1();
    system("cls");
    if (health > 0)
    {
        level2();
    }
    fileSave("LeaderBoard", name, score);
    gotoxy(0, 31);
    return 0;
}
//************level 1***************
int level1()
{
    drawLevel();
    int playerXCoordinate = 55, playerYCoordinate = 28;
    int skullXCoordinate[4] = {10, 68, 3, 60};
    int skullYCoordinate[4] = {15, 15, 3, 3};
    int fireXCoordinate = 56, fireYCoordinate = 15;
    string direction[4];
    int skullHealth[4] = {200, 200, 200, 200};
    skull(skullXCoordinate[0], skullYCoordinate[0]);
    skull(skullXCoordinate[1], skullYCoordinate[1]);
    skull(skullXCoordinate[2], skullYCoordinate[2]);
    skull(skullXCoordinate[3], skullYCoordinate[3]);
    player(playerXCoordinate, playerYCoordinate);
    hideCursor();
    int timer = 0;
    while (true)
    {
        playerMove(playerXCoordinate, playerYCoordinate, score, health);
        fireFromEnemyDetect(playerXCoordinate, playerYCoordinate, health);
        if (timer % 2 == 0)
        {

            eraseSkull(skullXCoordinate[0], skullYCoordinate[0], playerXCoordinate, playerYCoordinate);
            eraseSkull(skullXCoordinate[1], skullYCoordinate[1], playerXCoordinate, playerYCoordinate);
            eraseSkull(skullXCoordinate[2], skullYCoordinate[2], playerXCoordinate, playerYCoordinate);
            eraseSkull(skullXCoordinate[3], skullYCoordinate[3], playerXCoordinate, playerYCoordinate);

            leftToRight(skullXCoordinate, skullYCoordinate, direction);

            points(score);
            playerHealth(health);
            if (skullHealth[0] > 0)
            {
                skull(skullXCoordinate[0], skullYCoordinate[0]);
                moveBulletenemy();
            }
            else
            {
                eraseSkull(skullXCoordinate[0], skullYCoordinate[0], playerXCoordinate, playerYCoordinate);
            }
            if (skullHealth[1] > 0)
            {
                skull(skullXCoordinate[1], skullYCoordinate[1]);
                moveBulletenemy();
            }
            else
            {
                eraseSkull(skullXCoordinate[1], skullYCoordinate[1], playerXCoordinate, playerYCoordinate);
            }
            if (skullHealth[2] > 0)
            {
                skull(skullXCoordinate[2], skullYCoordinate[2]);
                moveBulletRightEnemy();
            }
            else
            {
                eraseSkull(skullXCoordinate[2], skullYCoordinate[2], playerXCoordinate, playerYCoordinate);
            }
            if (skullHealth[3] > 0)
            {
                skull(skullXCoordinate[3], skullYCoordinate[3]);
                moveBulletLeftEnemy();
            }
            else
            {
                eraseSkull(skullXCoordinate[3], skullYCoordinate[3], playerXCoordinate, playerYCoordinate);
            }

            moveBullet(skullXCoordinate, score, skullHealth);
            movefireBombDown(health);
            movefireBombUp(health);
        }

        checkCollisions(playerXCoordinate, playerYCoordinate, health);
        generateEnemyAttacks(skullXCoordinate, skullYCoordinate, fireXCoordinate, fireYCoordinate, timer, skullHealth);

        if (health <= 0) // losing condition
        {
            system("cls");
            gameOver();
            cout << endl
                 << endl;
            cout << endl
                 << "Final Score: " << score << endl;
            // getch();
            cin.get();
            break;
        }
        bool winCharacter = false;

        if (playerYCoordinate < 5 && playerXCoordinate > 100) // to reach near the door
        {
            winCharacter = true;
        }

        if (winCharacter && skullHealth[0] <= 0 && skullHealth[1] <= 0 && skullHealth[2] <= 0 && skullHealth[3] <= 0)
        {
            level2Instructions();
            cout << endl
                 << "Final Score: " << score << endl;

            FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
            cout << "Press Enter to continue...";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            break;
        }

        timer++;
        Sleep(2);
    }
    return health;
}

//***************Level 2*****************
void level2()
{
    system("cls");
    maze();
    briks1(1, 23);
    briks1(71, 23);
    briks(24, 14);
    drawLevel1();

    hideCursor();
    int playerLevel2XCoordinate = 1, playerLevel2YCoordinate = 28;
    player(playerLevel2XCoordinate, playerLevel2YCoordinate);
    int timer2 = 0;
    bool activeSpikes1 = false, activeSpikes2 = true;
    string directionMech[4] = {"right", "left", "down", "up"};
    int mechXCoordinate[4] = {24, 90, 8, 105}, mechYCoordinate[4] = {19, 19, 8, 20};
    int spiderX[2] = {10, 90}, spiderY[2] = {2, 2};
    int spiderHealth[2] = {200, 200};
    string spiderDirection[2] = {"right", "left"};
    int bossSpiderX = 27, bossSpiderY = 8;
    string bossSpiderDirection = "right";
    int bossHealth = 200;
    int mechHealth[4] = {200, 200, 200, 200};
    while (true)
    {
        if (timer2 % 2 == 0)
        {
            eraseMech(mechXCoordinate, mechYCoordinate, mechHealth, playerLevel2XCoordinate, playerLevel2YCoordinate);
            eraseEnemy(spiderX, spiderY, bossSpiderX, bossSpiderY, bossHealth, spiderHealth, playerLevel2XCoordinate, playerLevel2YCoordinate);
            moveMech(mechXCoordinate, mechYCoordinate, directionMech);
            moveSpider(spiderX, spiderDirection);
            moveBossSpider(bossSpiderX, bossSpiderDirection);
            for (int i = 0; i < 4; i++)
            {
                if (mechHealth[i] > 0)
                {
                    drawMech(mechXCoordinate[i], mechYCoordinate[i]);
                }
            }
            for (int i = 0; i < 2; i++)
            {
                if (spiderHealth[i] > 0)
                {
                    drawSpider(spiderX[i], spiderY[i]);
                }
            }
            if (bossHealth > 0)
            {
                drawBossSpider(bossSpiderX, bossSpiderY);
            }
        }

        moveBulletBossSpiderRight();
        moveBulletBossSpiderLeft();
        generateEnemyAttach(spiderHealth, spiderX, spiderY, timer2, bossSpiderX, bossSpiderY, bossHealth);
        checkCollisions(playerLevel2XCoordinate, playerLevel2YCoordinate, health);
        playerMove(playerLevel2XCoordinate, playerLevel2YCoordinate, score, health);
        moveBulletLevel2(mechXCoordinate, mechYCoordinate, score, mechHealth, spiderX, spiderHealth, bossSpiderX, bossHealth);

        points(score);
        specialWeaponAndFire(playerLevel2XCoordinate, playerLevel2YCoordinate, score);
        fireFromEnemyDetect(playerLevel2XCoordinate, playerLevel2YCoordinate, health);
        playerHealth(health);
        if (timer2 % 30 < 20)
        {
            activeSpikes1 = true;
            activeSpikes2 = false;
        }
        else
        {
            activeSpikes1 = false;
            activeSpikes2 = true;
        }
        if (health <= 0) // losing condition
        {
            system("cls");
            gameOver();
            cout << endl
                 << endl;
            cout << "Final Score: " << score << endl;
            getch();
            break;
        }

        bool allMechsDead = true;
        for (int i = 0; i < 4; i++)
        {
            if (mechHealth[i] > 0)
                allMechsDead = false;
        }

        bool allSpidersDead = (spiderHealth[0] <= 0 && spiderHealth[1] <= 0);
        bool winCharacter = false;

        if (playerLevel2YCoordinate <= 6 && playerLevel2XCoordinate <= 55 && playerLevel2XCoordinate >= 50) // to reach near prison
        {
            winCharacter = true;
        }
        if ((bossHealth <= 0 && allMechsDead && allSpidersDead) && winCharacter)
        {
            system("cls");
            youWin();
            cout << endl;
            cout << "Final Score: " << score << endl;
            break;
        }
        moveBulletenemy();
        drawSpikes(55, 25, activeSpikes1);
        Sleep(2);
        timer2++;
    }
}
//***************************************

void header()
{
    SetConsoleOutputCP(CP_UTF8);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 12);
    int row = 10;
    int col = 3;
    const char *headerLines[] = {
        "███████╗██╗  ██╗██╗   ██╗██╗     ██╗         ███████╗██╗ ██████╗ ██╗  ██╗████████╗███████╗██████╗ ",
        "██╔════╝██║ ██╔╝██║   ██║██║     ██║         ██╔════╝██║██╔════╝ ██║  ██║╚══██╔══╝██╔════╝██╔══██╗",
        "███████╗█████╔╝ ██║   ██║██║     ██║         █████╗  ██║██║  ███╗███████║   ██║   █████╗  ██████╔╝",
        "╚════██║██╔═██╗ ██║   ██║██║     ██║         ██╔══╝  ██║██║   ██║██╔══██║   ██║   ██╔══╝  ██╔══██╗",
        "███████║██║  ██╗╚██████╔╝███████╗███████╗    ██║     ██║╚██████╔╝██║  ██║   ██║   ███████╗██║  ██╗",
        "╚══════╝╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚══════╝    ╚═╝     ╚═╝ ╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝"};
    const int numLines = sizeof(headerLines) / sizeof(headerLines[0]);
    for (int i = 0; i < numLines; i++)
    {
        gotoxy(row, col + i);
        cout << headerLines[i];
    }
    cout << endl
         << endl;
    SetConsoleTextAttribute(hConsole, 7);
}
void drawLevel()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 1);
    printDoor(112, 1);
    SetConsoleTextAttribute(hConsole, 2);
    printTree(18, 25);
    printTree(95, 25);
    printTree(13, 7);
    printTree(100, 7);
    SetConsoleTextAttribute(hConsole, 4);
    printHeart(70, 12);
    printHeart(95, 18);
    printHeart(35, 11);
    printHeart(40, 20);
    printHeart(2, 15);
    printHeart(45, 30);
    printCoin(80, 11);
    printCoin(2, 2);
    printCoin(4, 25);
    printCoin(110, 25);
    printCoin(110, 6);
    printCoin(55, 3);
    SetConsoleTextAttribute(hConsole, 14);
    drawFire(56, 15);
}
void printDoor(int x, int y)
{
    gotoxy(x, y);
    cout << " ___ ";
    gotoxy(x, y + 1);
    cout << "| | |";
    gotoxy(x, y + 2);
    cout << "| | |";
    gotoxy(x, y + 3);
    cout << "|_o_|";
}
void drawFire(int x, int y)
{
    char fire[4][6] = {{"  ) "},
                       {" ( ) "},
                       {" ) ( "},
                       {"  |  "}};
    for (int i = 0; i < 4; i++)
    {
        gotoxy(x, y + i);
        cout << fire[i] << endl;
    }
}
void printTree(int x, int y)
{
    gotoxy(x, y);
    cout << "  ^  ";
    gotoxy(x, y + 1);
    cout << " ^^^ ";
    gotoxy(x, y + 2);
    cout << "^^^^^ ";
    gotoxy(x, y + 3);
    cout << "  |  ";
}
void printHeart(int x, int y)
{
    gotoxy(x, y);
    cout << "+";
}
void printCoin(int x, int y)
{
    gotoxy(x, y);
    cout << "[o]";
}
void gameOver()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 12);
    cout << " $$$$$$\\                                           $$$$$$\\                                 " << endl;
    cout << "$$  __$$\\                                         $$  __$$\\                                " << endl;
    cout << "$$ /  \\__| $$$$$$\\  $$$$$$\\$$\\$$\\   $$$$$$\\       $$ /  $$ |$$\\    $$\\  $$$$$$\\   $$$$$$\\  " << endl;
    cout << "$$ |$$$$\\  \\____$$\\ $$  _$$  _$$\\ $$  __$$\\       $$ |  $$ |\\$$\\  $$  |$$  __$$\\ $$  __$$\\ " << endl;
    cout << "$$ |\\_$$ | $$$$$$$ |$$ / $$ / $$ |$$$$$$$$ |      $$ |  $$ | \\$$\\$$  / $$$$$$$$ |$$ |  \\__|" << endl;
    cout << "$$ |  $$ |$$  __$$ |$$ | $$ | $$ |$$   ____|      $$ |  $$ |  \\$$$  /  $$   ____|$$ |      " << endl;
    cout << "\\$$$$$$  |\\$$$$$$$ |$$ | $$ | $$ |\\$$$$$$$\\        $$$$$$  |   \\$  /   \\$$$$$$$\\ $$ |      " << endl;
    cout << " \\______/  \\_______|\\__| \\__| \\__| \\_______|       \\______/     \\_/     \\_______|\\__|      " << endl;
    cout << "\a";
}
void youWin()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);
    cout << "$$\\     $$\\                         $$\\      $$\\ $$\\           " << endl;
    cout << "\\$$\\   $$  |                        $$ | $\\  $$ |\\__|          " << endl;
    cout << " \\$$\\ $$  /$$$$$$\\  $$\\   $$\\       $$ |$$$\\ $$ |$$\\ $$$$$$$\\  " << endl;
    cout << "  \\$$$$  /$$  __$$\\ $$ |  $$ |      $$ $$ $\\\\$$ |$$ |$$  __$$\\ " << endl;
    cout << "   \\$$  / $$ /  $$ |$$ |  $$ |      $$$$  _$$$$ |$$ |$$ |  $$ |" << endl;
    cout << "    $$ |  $$ |  $$ |$$ |  $$ |      $$$  / \\$$$ |$$ |$$ |  $$ |" << endl;
    cout << "    $$ |  \\$$$$$$  |\\$$$$$$  |      $$  /   \\$$ |$$ |$$ |  $$ |" << endl;
    cout << "    \\__|   \\______/  \\______/       \\__/     \\__|\\__|\\__|  \\__|" << endl;
    cout << "\a";
}
void maze()
{
    SetConsoleOutputCP(437);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11);
    const int height = 15;
    const int width = 118;
    const int widthOfBorder = 60;
    int z = 0;
    drawMazeBorder(widthOfBorder);
    cout << endl;
    while (z < height)
    {
        drawMazeWalls(width);
        z++;
    }
    drawMazeBorder(widthOfBorder);
}
void drawMazeWalls(int width)
{
    char solid = 219, dotted = 176;
    int row = 0;
    cout << dotted;
    while (row < width)
    {
        cout << " ";
        row++;
    }
    cout << solid;
    cout << endl;
    row = 0;
    cout << solid;
    while (row < width)
    {
        cout << " ";
        row++;
    }
    cout << dotted;
    cout << endl;
}
void drawMazeBorder(int width)
{
    int counter = 0;
    char solid = 219, dotted = 176;
    while (counter < width)
    {
        cout << dotted << solid;
        counter++;
    }
}
void hideCursor()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &info);
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
string menu()
{
    string name;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    header();

    SetConsoleTextAttribute(hConsole, 3);
    const char *const menuLines[] = {
        "==========================================================",
        "                    HOW TO PLAY                           ",
        "==========================================================",
        "1. MOVEMENT: Use Arrow Keys to move your player.",
        "2. ATTACK:   Press [SPACE] to fire at the enemies.",
        "",
        "--- SCORING & HEALTH ---",
        "* ELIMINATE: Kill an enemy (Skull) to get Score.",
        "* COLLECT:   Pick up [+] to restore Health.",
        "* TREASURE:  Collect [o] coins for extra points.",
        "",
        "--- DANGERS ---",
        "* ENEMIES:   Touching Skulls or their bullets reduces Health.",
        "* TRAPS:     Avoid fire bombs and obstacles!",
        "",
        "--- WINNING CONDITION ---",
        "* Destroy ALL 4 Skulls and reach the door at the top right corner!",
        "=========================================================="};

    const int numMenuLines = sizeof(menuLines) / sizeof(menuLines[0]);
    int row = 30;
    int col = 10;
    for (int i = 0; i < numMenuLines; i++)
    {
        gotoxy(row, col + i);
        cout << menuLines[i];
    }

    int inputRow = col + numMenuLines;
    gotoxy(row, inputRow);
    cout << "Enter your Name: ";
    getline(cin, name);

    string input;
    while (true)
    {
        gotoxy(row, inputRow + 1);
        cout << "                                                        ";
        gotoxy(row, inputRow + 1);
        cout << "Press 'S' to start or 'L' for Leaderboard: ";
        cin >> input;
        if (input.length() == 1)
        {
            char start = input[0];
            if (start == 'S' || start == 's')
            {
                break;
            }
            else if (start == 'L' || start == 'l')
            {
                showLeaderBoard();
                handlePause();

                system("cls");
                maze();
                header();
                SetConsoleTextAttribute(hConsole, 3);
                for (int i = 0; i < numMenuLines; i++)
                {
                    gotoxy(row, col + i);
                    cout << menuLines[i];
                }
            }
            else
            {
                gotoxy(row, inputRow + 2);
                cout << "                                        ";
                gotoxy(row, inputRow + 2);
                cout << "Invalid Input, Try again.";
            }
        }
    }
    return name;
}
int handlePause()
{
    string pause;
    int x = 42;
    int y = 18;
    gotoxy(x, y);
    cout << "Type 'next' to continue: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, pause);

    while (pause != "next")
    {
        gotoxy(x, y);
        cout << "                                        ";
        gotoxy(x, y);
        cout << "Invalid! Please type 'next': ";
        getline(cin, pause);
    }
    gotoxy(x, y);
    cout << "                                        ";
    gotoxy(x, y);
    cout << "Continuing..." << endl;

    return 0;
}
void points(int score)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);
    gotoxy(122, 1);
    cout << "         ";
    gotoxy(122, 1);
    cout << "Score:" << score;
}
void playerHealth(int health)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);
    gotoxy(122, 3);
    cout << "           ";
    gotoxy(122, 3);
    cout << "Health:" << health;
}
char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD bufSize = {1, 1};

    if (ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, bufSize, xy, &rect))
    {
        return ci.Char.AsciiChar;
    }
    return ' ';
}

void player(int &px, int &py)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 3);
    char faceOfPlayer[3][10] = {
        {"  (^_^)  "},
        {" <)   (> "},
        {"  _|_|_  "}};

    for (int i = 0; i < 3; i++)
    {
        gotoxy(px, py + i);
        cout << faceOfPlayer[i];
    }
}
void playerErase(int &px, int &py)
{

    for (int i = 0; i < 3; i++)
    {
        gotoxy(px, py + i);
        cout << "         ";
    }
}
// Handles player movement, collision detection, pickups, damage,
// score updates, and boundary checks based on keyboard input.
void playerMove(int &playerXCo, int &playerYCo, int &score, int &health)
{
    if (GetAsyncKeyState(VK_UP))
    {
        char check;
        bool move = false;
        for (int i = 0; i < 9; i++)
        {
            check = getCharAtxy(playerXCo + i, playerYCo - 1);
            if (check == '+')
            {
                move = true;
                gotoxy(playerXCo + i, playerYCo - 1);
                cout << " ";
                health = health + 5;
                playerHealth(health);
            }
            if (check == 'm')
            {
                health -= 05;
                playerErase(playerXCo, playerYCo);
                playerXCo = 55;
                playerYCo = 28;
                player(playerXCo, playerYCo);
            }
            if (check == ' ' || check == 'o' || check == '[' || check == ']')
            {
                move = true;
            }
            else
            {
                move = false;
                break;
            }
            if (check == '[' || check == 'o' || check == ']')
            {
                score += 10;
                break;
            }
            if (check == '(' || check == ')' || check == '|')
            {
                move = false;
            }
        }
        if (move)
        {
            playerErase(playerXCo, playerYCo);
            playerYCo--;
            player(playerXCo, playerYCo);
        }
    }
    if (GetAsyncKeyState(VK_DOWN))
    {
        char check;
        bool move = false;
        int temp = playerYCo + 2;
        for (int i = 0; i < 9; i++)
        {
            check = getCharAtxy(playerXCo + i, temp + 1);
            if (check == '+')
            {
                move = true;
                gotoxy(playerXCo + i, temp + 1);
                cout << " ";
                health = health + 5;
                playerHealth(health);
            }
            if (check == '#')
            {
                move = true;
            }
            if (check == '-' || check == '.')
            {
                health -= 05;
                playerErase(playerXCo, playerYCo);
                playerXCo = 55;
                playerYCo = 28;
                player(playerXCo, playerYCo);
            }
            if (check == ' ' || check == 'o' || check == '[' || check == ']')
            {
                move = true;
            }
            else
            {
                move = false;
                break;
            }
            if (check == '[' || check == 'o' || check == ']')
            {
                score += 10;
                break;
            }
            if (check == '(' || check == ')' || check == '|')
            {
                move = false;
            }
        }
        if (move)
        {
            playerErase(playerXCo, playerYCo);
            playerYCo++;
            player(playerXCo, playerYCo);
        }
    }

    if (GetAsyncKeyState(VK_LEFT))
    {
        char check;
        bool move = false;
        for (int i = 0; i < 3; i++)
        {
            check = getCharAtxy(playerXCo - 1, playerYCo + i);
            if (check == '+')
            {
                move = true;
                gotoxy(playerXCo - 1, playerYCo + i);
                cout << " ";
                health = health + 5;
                playerHealth(health);
            }
            if (check == '#')
            {
                move = true;
            }
            if (check == ' ' || check == 'o' || check == '[' || check == ']')
            {
                move = true;
            }
            else
            {
                move = false;
                break;
            }
            if (check == '[' || check == 'o' || check == ']')
            {
                score += 10;
                gotoxy(playerXCo - 4, playerYCo + i);
                cout << "   ";
                break;
            }
            if (check == '(' || check == ')' || check == '|')
            {
                move = false;
            }
        }
        if (move)
        {
            playerErase(playerXCo, playerYCo);
            playerXCo--;
            player(playerXCo, playerYCo);
        }
    }
    if (GetAsyncKeyState(VK_RIGHT))
    {
        char check;
        bool move = false;
        int temp = playerXCo + 8;
        for (int i = 0; i < 3; i++)
        {
            check = getCharAtxy(temp + 1, playerYCo + i);
            if (check == '+')
            {
                move = true;
                gotoxy(temp + 1, playerYCo + i);
                cout << " ";
                health = health + 5;
                playerHealth(health);
            }
            if (check == '#')
            {
                move = true;
            }
            if (check == ' ' || check == 'o' || check == '[' || check == ']')
            {
                move = true;
            }
            else
            {
                move = false;
                break;
            }
            if (check == '[' || check == 'o' || check == ']')
            {
                score += 10;
                gotoxy(temp + 1, playerYCo + i);
                cout << "   ";
                break;
            }
            if (check == '(' || check == ')' || check == '|')
            {
                move = false;
            }
        }
        if (move)
        {
            playerErase(playerXCo, playerYCo);
            playerXCo++;
            player(playerXCo, playerYCo);
        }
    }
    if (GetAsyncKeyState(VK_SPACE))
    {
        char above = getCharAtxy(playerXCo + 4, playerYCo - 1);
        if (above != '_' && above != '|' && above != (char)219 && above != (char)176)
        {
            createBullet(playerXCo + 4, playerYCo - 1, "up");
        }
    }
    if (hasSpecialWeapon)
    {

        if (GetAsyncKeyState('X') || GetAsyncKeyState('x'))
        {
            char above = getCharAtxy(playerXCo + 8, playerYCo + 1);

            if (above != '_' && above != '|' && above != (char)219 && above != (char)176)
            {
                createBullet(playerXCo + 8, playerYCo + 1, "right");
            }
        }
        if (GetAsyncKeyState('Z') || GetAsyncKeyState('z'))
        {
            char above = getCharAtxy(playerXCo - 1, playerYCo + 1);

            if (above != '_' && above != '|' && above != (char)219 && above != (char)176)
            {
                createBullet(playerXCo - 1, playerYCo + 1, "left");
            }
        }
    }
}
void createBullet(int x, int y, string direction)
{
    bulletX[bulletCount] = x;
    bulletY[bulletCount] = y;
    bulletDirection[bulletCount] = direction;
    printBullet(x, y);
    bulletCount++;
}
void printBullet(int x, int y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);
    gotoxy(x, y);
    cout << "^";
}
void eraseBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
// Moves player bullets upward, handles skull collisions, damage, scoring, and bullet removal
void moveBullet(int skullXCoordinate[], int &score, int skullHealth[])
{
    for (int idx = 0; idx < bulletCount; idx++)
    {
        char next = getCharAtxy(bulletX[idx], bulletY[idx] - 1);

        if (next == ' ')
        {
            eraseBullet(bulletX[idx], bulletY[idx]);
            bulletY[idx]--;
            printBullet(bulletX[idx], bulletY[idx]);
        }
        else if (next == 'm' || next == 'o' || next == '-' || next == '|')
        {
            if (bulletX[idx] >= skullXCoordinate[0] && bulletX[idx] <= skullXCoordinate[0] + 7)
            {
                if (skullHealth[0] > 0)
                {
                    skullHealth[0] -= 10;
                    if (skullHealth[0] <= 0)
                    {
                        score += 5;
                    }
                }
            }
            else if (bulletX[idx] >= skullXCoordinate[1] && bulletX[idx] <= skullXCoordinate[1] + 7)
            {
                if (skullHealth[1] > 0)
                {
                    skullHealth[1] -= 10;
                    if (skullHealth[1] <= 0)
                    {
                        score += 5;
                    }
                }
            }
            else if (bulletX[idx] >= skullXCoordinate[2] && bulletX[idx] <= skullXCoordinate[2] + 7)
            {
                if (skullHealth[2] > 0)
                {
                    skullHealth[2] -= 10;
                    if (skullHealth[2] <= 0)
                    {
                        score += 5;
                    }
                }
            }
            else if (bulletX[idx] >= skullXCoordinate[3] && bulletX[idx] <= skullXCoordinate[3] + 7)
            {
                if (skullHealth[3] > 0)
                {
                    skullHealth[3] -= 10;
                    if (skullHealth[3] <= 0)
                    {
                        score += 5;
                    }
                }
            }

            eraseBullet(bulletX[idx], bulletY[idx]);
            bulletX[idx] = bulletX[bulletCount - 1];
            bulletY[idx] = bulletY[bulletCount - 1];
            bulletCount--;
            idx--;
        }
        else if (next == '_' || next == 219 || next == 176)
        {
            eraseBullet(bulletX[idx], bulletY[idx]);
            bulletX[idx] = bulletX[bulletCount - 1];
            bulletY[idx] = bulletY[bulletCount - 1];
            bulletCount--;
            idx--;
        }
        else
        {
            eraseBullet(bulletX[idx], bulletY[idx]);
            bulletX[idx] = bulletX[bulletCount - 1];
            bulletY[idx] = bulletY[bulletCount - 1];
            bulletCount--;
            idx--;
        }
    }
}
// Erases a 3x7 sprite area without removing pixels that overlap the player
void smartEraseLogic(int x, int y, int px, int py)
{
    const int spriteHeight = 3;
    const int spriteWidth = 7;
    const int playerWidth = 11;
    const int playerHeight = 3;

    for (int i = 0; i < spriteHeight; i++)
    {
        for (int j = 0; j < spriteWidth; j++)
        {
            int currentX = x + j;
            int currentY = y + i;

            bool overlapsPlayer = (currentX >= px && currentX < px + playerWidth &&
                                   currentY >= py && currentY < py + playerHeight);

            if (!overlapsPlayer)
            {
                if (getCharAtxy(currentX, currentY) != ' ')
                {
                    gotoxy(currentX, currentY);
                    cout << " ";
                }
            }
        }
    }
}

void skull(int &ex, int &ey)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 6);
    char skull[3][8] = {
        {" .---. "},
        {"| o o |"},
        {" m m m "}};
    for (int i = 0; i < 3; i++)
    {
        gotoxy(ex, ey + i);
        cout << skull[i];
    }
}
void eraseSkull(int &eX, int &eY, int px, int py)
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            int currentX = eX + j;
            int currentY = eY + i;
            bool isPlayerZone = (currentX >= px && currentX < px + 11 && currentY >= py && currentY < py + 3);

            // 2. ONLY erase if we are OUTSIDE the player zone
            if (!isPlayerZone)
            {
                char current = getCharAtxy(currentX, currentY);
                if (current != ' ')
                {
                    gotoxy(currentX, currentY);
                    cout << " ";
                }
            }
        }
    }
}
void createBulletForSull(int x, int y)
{
    enemyBulletX[enemyBulletCount] = x;
    enemyBulletY[enemyBulletCount] = y;
    printBulletForEnemy(x, y);
    enemyBulletCount++;
}
void printBulletForEnemy(int x, int y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 14);
    gotoxy(x, y);
    cout << "*";
}
void eraseBulletEnemy(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void moveBulletenemy()
{
    for (int idx = 0; idx < enemyBulletCount; idx++)
    {
        if (getCharAtxy(enemyBulletX[idx], enemyBulletY[idx] + 1) == ' ')
        {
            eraseBulletEnemy(enemyBulletX[idx], enemyBulletY[idx]);
            enemyBulletY[idx]++;
            printBulletForEnemy(enemyBulletX[idx], enemyBulletY[idx]);
        }
        else
        {
            eraseBulletEnemy(enemyBulletX[idx], enemyBulletY[idx]);
            enemyBulletX[idx] = enemyBulletX[enemyBulletCount - 1];
            enemyBulletY[idx] = enemyBulletY[enemyBulletCount - 1];
            enemyBulletCount--;
            idx--;
        }
    }
}
void moveBulletRightEnemy()
{
    for (int idx = 0; idx < bulletCountRight; idx++)
    {
        char next = getCharAtxy(bulletRightX[idx] + 1, bulletRightY[idx]);

        if (next == ' ')
        {
            eraseBulletEnemy(bulletRightX[idx], bulletRightY[idx]);
            bulletRightX[idx]++;
            printBulletForEnemy(bulletRightX[idx], bulletRightY[idx]);
        }
        else
        {
            eraseBulletEnemy(bulletRightX[idx], bulletRightY[idx]);
            bulletRightX[idx] = bulletRightX[bulletCountRight - 1];
            bulletRightY[idx] = bulletRightY[bulletCountRight - 1];
            bulletCountRight--;
            idx--;
        }
    }
}
void createBulletForSull3Right(int x, int y)
{
    bulletRightX[bulletCountRight] = x;
    bulletRightY[bulletCountRight] = y;
    printBulletForEnemy(x, y);
    bulletCountRight++;
}
void moveBulletLeftEnemy()
{
    for (int idx = 0; idx < bulletCountLeft; idx++)
    {
        char next = getCharAtxy(bulletLeftX[idx] - 1, bulletLeftY[idx]);

        if (next == ' ')
        {
            eraseBulletEnemy(bulletLeftX[idx], bulletLeftY[idx]);
            bulletLeftX[idx]--;
            printBulletForEnemy(bulletLeftX[idx], bulletLeftY[idx]);
        }
        else
        {
            eraseBulletEnemy(bulletLeftX[idx], bulletLeftY[idx]);
            bulletLeftX[idx] = bulletLeftX[bulletCountLeft - 1];
            bulletLeftY[idx] = bulletLeftY[bulletCountLeft - 1];
            bulletCountLeft--;
            idx--;
        }
    }
}
void createBulletForSull4Left(int x, int y)
{
    bulletLeftX[bulletCountLeft] = x;
    bulletLeftY[bulletCountLeft] = y;
    printBulletForEnemy(x, y);
    bulletCountLeft++;
}
// Controls horizontal movement of skull enemies and reverses direction at lane boundaries
void leftToRight(int skullXCoordinate[], int skullYCoordinate[], string direction[])
{
    if (skullXCoordinate[1] == 92)
    {
        direction[1] = "left";
    }
    if (skullXCoordinate[1] == 68)
    {
        direction[1] = "right";
    }
    if (skullXCoordinate[0] == 40)
    {
        direction[0] = "left";
    }
    if (skullXCoordinate[0] == 10)
    {
        direction[0] = "right";
    }
    if (skullXCoordinate[2] == 45)
    {
        direction[2] = "left";
    }
    if (skullXCoordinate[2] == 3)
    {
        direction[2] = "right";
    }
    if (skullXCoordinate[3] == 60)
    {
        direction[3] = "right";
    }
    if (skullXCoordinate[3] == 90)
    {
        direction[3] = "left";
    }

    if (direction[1] == "right")
    {
        skullXCoordinate[1]++;
    }
    if (direction[0] == "right")
    {
        skullXCoordinate[0]++;
    }
    if (direction[2] == "right")
    {
        skullXCoordinate[2]++;
    }
    if (direction[3] == "right")
    {
        skullXCoordinate[3]++;
    }
    if (direction[1] == "left")
    {
        skullXCoordinate[1]--;
    }
    if (direction[0] == "left")
    {

        skullXCoordinate[0]--;
    }
    if (direction[2] == "left")
    {

        skullXCoordinate[2]--;
    }
    if (direction[3] == "left")
    {

        skullXCoordinate[3]--;
    }
}

void createFireBombUp(int x, int y)
{
    fireBombUpX[fireBombUpCount] = x;
    fireBombUpY[fireBombUpCount] = y;
    printFireBomb(x, y);
    fireBombUpCount++;
}
void printFireBomb(int x, int y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 14);
    gotoxy(x, y);
    cout << "@";
}
void erasefireBomb(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void movefireBombUp(int &health)
{
    for (int idx = 0; idx < fireBombUpCount; idx++)
    {
        char next = getCharAtxy(fireBombUpX[idx], fireBombUpY[idx] - 1);

        if (next == ' ')
        {
            erasefireBomb(fireBombUpX[idx], fireBombUpY[idx]);
            fireBombUpY[idx]--;
            printFireBomb(fireBombUpX[idx], fireBombUpY[idx]);
        }
        else if (next == '|' || next == '_')
        {
            health = health - 10;
            erasefireBomb(fireBombUpX[idx], fireBombUpY[idx]);
            fireBombUpX[idx] = fireBombUpX[fireBombUpCount - 1];
            fireBombUpY[idx] = fireBombUpY[fireBombUpCount - 1];
            fireBombUpCount--;
            idx--;
        }
        else
        {
            erasefireBomb(fireBombUpX[idx], fireBombUpY[idx]);
            fireBombUpX[idx] = fireBombUpX[fireBombUpCount - 1];
            fireBombUpY[idx] = fireBombUpY[fireBombUpCount - 1];
            fireBombUpCount--;
            idx--;
        }
    }
}
void createFireBomb(int x, int y)
{
    fireBombDownX[fireBombDownCount] = x;
    fireBombDownY[fireBombDownCount] = y;
    printFireBomb(x, y);
    fireBombDownCount++;
}
void movefireBombDown(int &health)
{
    for (int idx = 0; idx < fireBombDownCount; idx++)
    {
        char next = getCharAtxy(fireBombDownX[idx], fireBombDownY[idx] + 1);

        if (next == ' ')
        {
            erasefireBomb(fireBombDownX[idx], fireBombDownY[idx]);
            fireBombDownY[idx]++;
            printFireBomb(fireBombDownX[idx], fireBombDownY[idx]);
        }
        else
        {
            erasefireBomb(fireBombDownX[idx], fireBombDownY[idx]);

            if (next == '(' || next == '^' || next == ')' || next == '_')
            {
                health = health - 10;
            }

            fireBombDownX[idx] = fireBombDownX[fireBombDownCount - 1];
            fireBombDownY[idx] = fireBombDownY[fireBombDownCount - 1];
            fireBombDownCount--;
            idx--;
        }
    }
}

void fireFromEnemyDetect(int px, int py, int &health)
{
    for (int i = 0; i < 9; i++)
    {
        if (getCharAtxy(px + i, py - 1) == '*' || getCharAtxy(px + i, py - 1) == '{' || getCharAtxy(px + i, py - 1) == '}' || getCharAtxy(px + i, py - 1) == 'X')
        {
            health = health - 5;
            eraseBulletEnemy(px + i, py - 1);
            playerHealth(health);
            player(px, py);
            return;
        }
        if (getCharAtxy(px + i, py + 3) == '*' || getCharAtxy(px + i, py + 3) == '{' || getCharAtxy(px + i, py + 3) == '}' || getCharAtxy(px + i, py + 3) == 'X')
        {
            health = health - 5;
            eraseBulletEnemy(px + i, py + 3);
            playerHealth(health);
            player(px, py);
            return;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (getCharAtxy(px - 1, py + i) == '*' || getCharAtxy(px - 1, py + i) == '{' || getCharAtxy(px - 1, py + i) == '}' || getCharAtxy(px - 1, py + i) == 'X')
        {
            health -= 5;

            eraseBulletEnemy(px - 1, py + i);
            playerHealth(health);
            player(px, py);
            return;
        }
        if (getCharAtxy(px + 9, py + i) == '*' || getCharAtxy(px + 9, py + i) == '{' || getCharAtxy(px + 9, py + i) == '}' || getCharAtxy(px + 9, py + i) == 'X')
        {
            health -= 5;
            eraseBulletEnemy(px + 9, py + i);
            playerHealth(health);
            player(px, py);
            return;
        }
    }
}
// detects colliosn with enemies
void checkCollisions(int &px, int &py, int &health)
{
    char topLeft = getCharAtxy(px, py);
    char topRight = getCharAtxy(px + 8, py);
    char bottomLeft = getCharAtxy(px, py + 2);
    char bottomRight = getCharAtxy(px + 8, py + 2);

    if (topLeft == 'm' || topLeft == '|' || topLeft == '-' || topLeft == 'o' ||
        topLeft == '<' || topLeft == '>' || topLeft == '\\' || topLeft == '/' ||
        topLeft == '(' || topLeft == ')' ||

        topRight == 'm' || topRight == '|' || topRight == '-' || topRight == 'o' ||
        topRight == '<' || topRight == '>' || topRight == '\\' || topRight == '/' ||
        topRight == '(' || topRight == ')' ||

        bottomLeft == 'm' || bottomLeft == '|' || bottomLeft == '-' || bottomLeft == 'o' ||
        bottomLeft == '<' || bottomLeft == '>' || bottomLeft == '\\' || bottomLeft == '/' ||
        bottomLeft == '(' || bottomLeft == ')' ||

        bottomRight == 'm' || bottomRight == '|' || bottomRight == '-' || bottomRight == 'o' ||
        bottomRight == '<' || bottomRight == '>' || bottomRight == '\\' || bottomRight == '/' ||
        bottomRight == '(' || bottomRight == ')')
    {
        health -= 5;

        playerErase(px, py);
        px = 55;
        py = 28;
        player(px, py);
    }
}
// prodcces fire enemy  , % operator is used for slow speed
void generateEnemyAttacks(int sX[], int sY[], int fireX, int fireY, int timer, int skullHealth[])
{
    if (timer % 20 == 0)
        if (skullHealth[0] > 0 && skullHealth[1] > 0)
        {
            createBulletForSull(sX[0] + 6, sY[0] + 4);
            createBulletForSull(sX[1] + 6, sY[1] + 4);
        }

    if (timer % 30 == 0)
    {
        if (skullHealth[3] > 0)
        {
            createBulletForSull4Left(sX[3] - 1, sY[3] + 1);
        }
    }

    if (timer % 10 == 0)
        if (skullHealth[2] > 0)
        {
            createBulletForSull3Right(sX[2] + 9, sY[2] + 1);
        }

    if (timer % 100 == 0)
    {
        createFireBomb(fireX + 3, fireY + 3);
        createFireBombUp(fireX + 1, fireY - 1);
    }
}

//---------functions of level2--------
void drawLevel1()
{
    printPrison(55, 1);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!hasSpecialWeapon)
    {
        SetConsoleTextAttribute(hConsole, 14);
        gotoxy(110, 27);
        cout << " $$$ ";
        gotoxy(110, 28);
        cout << "[ W ]"; // W for Weapon
        gotoxy(110, 29);
        cout << " $$$ ";
    }
    SetConsoleTextAttribute(hConsole, 2);
    printHeart(100, 28);
    printCoin(20, 8);
    printHeart(100, 8);
    printHeart(30, 27);
    SetConsoleTextAttribute(hConsole, 14);
    drawFire(1, 20);
    drawFire(113, 20);
    SetConsoleTextAttribute(hConsole, 10);
    printTree(113, 1);
    printTree(1, 1);
}
void level2Instructions()
{
    system("cls");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 14);

    cout << "==========================================================" << endl;
    cout << "             CONGRATULATIONS! LEVEL 1 CLEARED             " << endl;
    cout << "==========================================================" << endl;

    SetConsoleTextAttribute(hConsole, 7);
    cout << "\n--- NEW ABILITIES ---" << endl;
    cout << "* SPECIAL WEAPON: Find the [ W ] at the bottom right." << endl;
    cout << "* FIRE POWER: Once you pick 'W', you can fire Left/Right(X for left or Z for right fire)." << endl;
    cout << "* SCORE BONUS: Picking up 'W' gives extra points also!" << endl;

    SetConsoleTextAttribute(hConsole, 12);
    cout << "\n--- NEW ENEMIES ---" << endl;
    cout << "* BOSS SPIDER: Watch out for the giant spider at the top!" << endl;
    cout << "* SPIKES: Stay off the ground when spikes [^^^^] are active." << endl;

    SetConsoleTextAttribute(hConsole, 7);
    cout << "\n--- MISSION ---" << endl;
    cout << "* Destroy the Boss, all Mechs, and all Spiders." << endl;
    cout << "* Reach the Prison to the game!" << endl;
    cout << "==========================================================" << endl;
}
void briks(int x, int y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 6);
    int temp, yControl = 0;
    string briks[2] = {" __________ ", "|__________|"};
    int temporary = 0;
    for (int i = 1; i <= 12; i++)
    {
        if (temporary % 2 == 0)
        {
            if (temporary != 0)
            {
                x = x + 12;
                yControl -= 2;
            }
        }

        if (i % 2 == 0)
        {

            gotoxy(x, y + yControl);
            cout << briks[0] << endl;
        }
        else
        {
            temp = yControl + 2;
            gotoxy(x, y + temp);
            cout << briks[1] << endl;
        }
        yControl++;
        temporary++;
    }
}
void briks1(int x, int y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 6);
    int temp, yControl = 0;
    string briks[2] = {" __________ ", "|__________|"};
    int temporary = 0;
    for (int i = 1; i <= 8; i++)
    {
        if (temporary % 2 == 0)
        {
            if (temporary != 0)
            {
                x = x + 12;
                yControl -= 2;
            }
        }

        if (i % 2 == 0)
        {

            gotoxy(x, y + yControl);
            cout << briks[0] << endl;
        }
        else
        {
            temp = yControl + 2;
            gotoxy(x, y + temp);
            cout << briks[1] << endl;
        }
        yControl++;
        temporary++;
    }
}
void drawSpikes(int x, int y, bool active)
{
    gotoxy(x, y);
    if (active)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 11);
        cout << "^^^^^^^^^^^^";
    }
    else
    {
        cout << "            ";
    }
}
void drawSpider(int x, int y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 13);

    gotoxy(x, y);
    cout << " /\\_/\\ ";
    gotoxy(x, y + 1);
    cout << "( o_o )";
    gotoxy(x, y + 2);
    cout << "/|___|\\";
}
void drawBossSpider(int x, int y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 4);

    gotoxy(x, y);
    cout << "    _  _     _  _   ";
    gotoxy(x, y + 1);
    cout << "   //  \\\\___//  \\\\  ";
    gotoxy(x, y + 2);
    cout << "  <|    (o_o)    |> ";
    gotoxy(x, y + 3);
    cout << "   \\\\__/|###|\\__//  ";
    gotoxy(x, y + 4);
    cout << "    ''  d---b  ''   ";
}
void eraseBossSpider(int x, int y, int px, int py)
{
    const int spiderHeight = 5;
    const int spiderWidth = 19;
    for (int i = 0; i < spiderHeight; i++)
    {
        for (int j = 0; j < spiderWidth; j++)
        {
            int currentX = x + j;
            int currentY = y + i;
            // Avoid erasing pixels that overlap the player area
            bool isPlayerZone = (currentX >= px && currentX < px + 11 && currentY >= py && currentY < py + 3);
            if (!isPlayerZone)
            {
                gotoxy(currentX, currentY);
                cout << " ";
            }
        }
    }
}
void eraseBombForBoss(int &x, int &y)
{
    gotoxy(x, y);
    cout << "   ";
}
void printBombForBoss(int &x, int &y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 14);
    gotoxy(x, y);
    cout << "{X}";
}
void createBulletForBossSpider(int x, int y)
{
    bossSpiderRightBulletX[bossBulletCountRight] = x;
    bossSpiderRightBulletY[bossBulletCountRight] = y;
    printBombForBoss(x, y);
    bossBulletCountRight++;
}
void createBulletForBossSpiderLeft(int x, int y)
{
    bossSpiderLeftBulletX[bossBulletCountLeft] = x;
    bossSpiderLeftBulletY[bossBulletCountLeft] = y;
    printBombForBoss(x, y);
    bossBulletCountLeft++;
}
void moveSpider(int spiderXCo[], string spiderDirection[])
{
    // Updates spider positions and reverses direction at boundary limits
    if (spiderXCo[0] == 10)
    {
        spiderDirection[0] = "right";
    }
    if (spiderXCo[0] == 45)
    {
        spiderDirection[0] = "left";
    }
    if (spiderXCo[1] == 100)
    {
        spiderDirection[1] = "left";
    }
    if (spiderXCo[1] == 65)
    {
        spiderDirection[1] = "right";
    }
    if (spiderDirection[0] == "right")
    {
        spiderXCo[0]++;
    }
    if (spiderDirection[0] == "left")
    {
        spiderXCo[0]--;
    }
    if (spiderDirection[1] == "right")
    {
        spiderXCo[1]++;
    }
    if (spiderDirection[1] == "left")
    {
        spiderXCo[1]--;
    }
}
void drawMech(int x, int y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11); // Dark Red (Color code 4)

    char skull[3][8] = {
        {" .---. "},
        {"| o o |"},
        {" m m m "}};
    for (int i = 0; i < 3; i++)
    {
        gotoxy(x, y + i);
        cout << skull[i];
    }
}
void eraseMech(int mechXCoordinate[], int mechYCoordinate[], int mechHealth[], int playerX, int playerY)
{

    for (int i = 0; i < 4; i++)
    {
        smartEraseLogic(mechXCoordinate[i], mechYCoordinate[i], playerX, playerY);
    }
}
void printPrison(int x, int y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);
    char prison[4][8] = {{" ___ "},
                         {"|||||"},
                         {"||o||"},
                         {"|_|_|"}};
    for (int i = 0; i < 4; i++)
    {
        gotoxy(x, y + i);
        cout << prison[i] << endl;
    }
}
void moveBossSpider(int &bX, string &bossSpiderDirection)
{
    if (bX == 27)
    {
        bossSpiderDirection = "right";
    }
    if (bX == 75)
    {
        bossSpiderDirection = "left";
    }
    if (bossSpiderDirection == "left")
    {
        bX--;
    }
    if (bossSpiderDirection == "right")
    {
        bX++;
    }
}
void eraseEnemy(int spiderX[], int spiderY[], int bossSpiderX, int bossSpiderY, int bossHealth, int spiderHealth[], int playerX, int playerY)
{
    eraseBossSpider(bossSpiderX, bossSpiderY, playerX, playerY);
    eraseSpider(spiderX[0], spiderY[0], playerX, playerY);
    eraseSpider(spiderX[1], spiderY[1], playerX, playerY);
}
void eraseInMove(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        gotoxy(x, y + i);
        cout << "       ";
    }
}
void moveMech(int mechXCo[], int mechYCo[], string directionMech[])
{
    if (mechXCo[0] == 24)
    {
        directionMech[0] = "right";
    }
    if (mechXCo[1] == 90)
    {
        directionMech[1] = "left";
    }
    if (mechYCo[2] == 8)
    {
        directionMech[2] = "down";
    }
    if (mechYCo[2] == 20)
    {
        directionMech[2] = "up";
    }
    if (mechYCo[3] == 20)
    {
        directionMech[3] = "up";
    }
    if (mechYCo[3] == 8)
    {
        directionMech[3] = "down";
    }
    if (mechXCo[0] == 55)
    {
        directionMech[0] = "left";
    }
    if (mechXCo[1] == 60)
    {
        directionMech[1] = "right";
    }
    if (directionMech[0] == "right")
    {
        mechXCo[0]++;
    }
    if (directionMech[0] == "left")
    {
        mechXCo[0]--;
    }
    if (directionMech[1] == "left")
    {
        mechXCo[1]--;
    }

    if (directionMech[1] == "right")
    {
        mechXCo[1]++;
    }
    if (directionMech[2] == "down")
    {
        mechYCo[2]++;
    }
    if (directionMech[3] == "down")
    {
        mechYCo[3]++;
    }
    if (directionMech[2] == "up")
    {
        mechYCo[2]--;
    }
    if (directionMech[3] == "up")
    {
        mechYCo[3]--;
    }
}
void eraseSpider(int x, int y, int px, int py)
{
    const int spiderHeight = 6;
    const int spiderWidth = 8;
    for (int i = 0; i < spiderHeight; i++)
    {
        for (int j = 0; j < spiderWidth; j++)
        {
            int currentX = x + j;
            int currentY = y + i;
            // Prevent erasing pixels that overlap the player area
            bool isPlayerZone = (currentX >= px && currentX < px + 11 && currentY >= py && currentY < py + 3);

            if (!isPlayerZone)
            {
                gotoxy(currentX, currentY);
                cout << " ";
            }
        }
    }
}
void moveBulletBossSpiderRight()
{
    for (int idx = 0; idx < bossBulletCountRight; idx++)
    {
        char next = getCharAtxy(bossSpiderRightBulletX[idx] + 3, bossSpiderRightBulletY[idx]);

        if (next == ' ')
        {
            eraseBombForBoss(bossSpiderRightBulletX[idx], bossSpiderRightBulletY[idx]);
            bossSpiderRightBulletX[idx]++;
            printBombForBoss(bossSpiderRightBulletX[idx], bossSpiderRightBulletY[idx]);
        }
        else
        {
            eraseBombForBoss(bossSpiderRightBulletX[idx], bossSpiderRightBulletY[idx]);
            bossSpiderRightBulletX[idx] = bossSpiderRightBulletX[bossBulletCountRight - 1];
            bossSpiderRightBulletY[idx] = bossSpiderRightBulletY[bossBulletCountRight - 1];
            bossBulletCountRight--;
            idx--;
        }
    }
}
void moveBulletBossSpiderLeft()
{
    for (int idx = 0; idx < bossBulletCountLeft; idx++)
    {
        char next = getCharAtxy(bossSpiderLeftBulletX[idx] - 1, bossSpiderLeftBulletY[idx]);

        if (next == ' ')
        {
            eraseBombForBoss(bossSpiderLeftBulletX[idx], bossSpiderLeftBulletY[idx]);
            bossSpiderLeftBulletX[idx]--;
            printBombForBoss(bossSpiderLeftBulletX[idx], bossSpiderLeftBulletY[idx]);
        }
        else
        {
            eraseBombForBoss(bossSpiderLeftBulletX[idx], bossSpiderLeftBulletY[idx]);
            bossSpiderLeftBulletX[idx] = bossSpiderLeftBulletX[bossBulletCountLeft - 1];
            bossSpiderLeftBulletY[idx] = bossSpiderLeftBulletY[bossBulletCountLeft - 1];
            bossBulletCountLeft--;
            idx--;
        }
    }
}
void generateEnemyAttach(int spiderHealth[], int sX[], int sY[], int timer, int bX, int bY, int &bossHealth)
{
    if (timer % 10 == 0)
    {
        if (spiderHealth[0] > 0)
        {
            createBulletForSull(sX[0] + 6, sY[0] + 4);
        }
    }

    if (timer % 10 == 0)
    {
        if (spiderHealth[1] > 0)
        {
            createBulletForSull(sX[1] + 6, sY[1] + 4);
        }
    }

    if (timer % 35 == 0)
    {
        if (bossHealth > 0)
        {
            createBulletForBossSpider(bX + 21, bY + 2);
            createBulletForBossSpiderLeft(bX - 2, bY + 2);
        }
    }
}
void specialWeaponAndFire(int playerLevel2XCoordinate, int playerLevel2YCoordinate, int &score)
{

    if (!hasSpecialWeapon && playerLevel2XCoordinate > 101 && playerLevel2YCoordinate <= 29 && playerLevel2YCoordinate >= 26)
    {
        hasSpecialWeapon = true;
        score = score + 20;
        points(score);

        for (int i = 0; i < 3; i++)
        {
            gotoxy(110, 27 + i);
            cout << "     ";
        }
    }
}
/* Handles bullet movement and collision detection in Level 2:
updates bullet position, applies damage to mechs, spiders, and boss,
removes bullets on impact, and updates score and enemy health accordingly. */
void moveBulletLevel2(int mechXCoordinate[], int mechYCoordinate[], int &score, int mechHealth[], int spiderX[], int spiderHealth[], int bossSpiderX, int &bossHealth)
{
    for (int idx = 0; idx < bulletCount; idx++)
    {
        char currentNext;
        if (bulletDirection[idx] == "up")
        {
            currentNext = getCharAtxy(bulletX[idx], bulletY[idx] - 1);
        }
        else if (bulletDirection[idx] == "right")
        {
            currentNext = getCharAtxy(bulletX[idx] + 1, bulletY[idx]);
        }
        else if (bulletDirection[idx] == "left")
        {
            currentNext = getCharAtxy(bulletX[idx] - 1, bulletY[idx]);
        }

        if (currentNext == ' ')
        {
            eraseBullet(bulletX[idx], bulletY[idx]);
            if (bulletDirection[idx] == "up")
                bulletY[idx]--;
            else if (bulletDirection[idx] == "right")
                bulletX[idx]++;
            else if (bulletDirection[idx] == "left")
                bulletX[idx]--;
            printBullet(bulletX[idx], bulletY[idx]);
        }
        else if (currentNext == 'm' || currentNext == 'o' || currentNext == '-' || currentNext == '|')
        {
            for (int i = 0; i < 4; i++)
            {
                if (bulletX[idx] >= mechXCoordinate[i] && bulletX[idx] <= mechXCoordinate[i] + 7)
                {
                    mechHealth[i] -= 10;
                    if (mechHealth[i] <= 0)
                    {
                        score += 5;
                    }
                    if (mechHealth[i] <= 0)
                    {
                        eraseInMove(mechXCoordinate[i], mechYCoordinate[i]);
                        mechHealth[i] = 0;
                    }
                }
            }
            eraseBullet(bulletX[idx], bulletY[idx]);
            bulletX[idx] = bulletX[bulletCount - 1];
            bulletY[idx] = bulletY[bulletCount - 1];
            bulletDirection[idx] = bulletDirection[bulletCount - 1];
            bulletCount--;
            idx--;
        }
        else if (currentNext == '(' || currentNext == ')' || currentNext == '_')
        {
            for (int i = 0; i < 2; i++)
            {
                if (bulletX[idx] >= spiderX[i] - 1 && bulletX[idx] <= spiderX[i] + 5)
                {
                    spiderHealth[i] -= 10;
                    if (spiderHealth[i] <= 0)
                    {
                        score += 5;
                    }
                }
            }
            eraseBullet(bulletX[idx], bulletY[idx]);
            bulletX[idx] = bulletX[bulletCount - 1];
            bulletY[idx] = bulletY[bulletCount - 1];
            bulletDirection[idx] = bulletDirection[bulletCount - 1];
            bulletCount--;
            idx--;
        }
        else if (currentNext == '/' || currentNext == '\\' || currentNext == '<' || currentNext == '>' || currentNext == 'b' || currentNext == 'd' || currentNext == '\'')
        {
            if (bulletX[idx] >= bossSpiderX && bulletX[idx] <= bossSpiderX + 19)
            {
                bossHealth -= 5;
                if (bossHealth <= 0)
                {
                    score += 5;
                }
            }
            eraseBullet(bulletX[idx], bulletY[idx]);
            bulletX[idx] = bulletX[bulletCount - 1];
            bulletY[idx] = bulletY[bulletCount - 1];
            bulletDirection[idx] = bulletDirection[bulletCount - 1];
            bulletCount--;
            idx--;
        }
        else
        {
            eraseBullet(bulletX[idx], bulletY[idx]);
            bulletX[idx] = bulletX[bulletCount - 1];
            bulletY[idx] = bulletY[bulletCount - 1];
            bulletDirection[idx] = bulletDirection[bulletCount - 1];
            bulletCount--;
            idx--;
        }
    }
}

void showLeaderBoard()
{
    system("cls");
    maze();
    header();
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 6);
    ifstream file("LeaderBoard");
    string name[200];
    int doneScore[200] = {0};
    int i = 0;

    while (i < 200 && getline(file, name[i])) {
        string scoreStr;
        if (getline(file, scoreStr)) {
            doneScore[i] = stoi(scoreStr);
            i++;
        }
    }
    file.close();

    sortPlayersDescending(name, doneScore, i);

    int x = 42, y = 10;
    gotoxy(x, y++);
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    gotoxy(x, y++);
    cout << "@ " << left << setw(20) << "Name" << setw(10) << "Score" << "   @" << endl;
    gotoxy(x, y++);
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;

    for (int j = 0; j < 3 && j < i; j++) {
        gotoxy(x, y++);
        cout << "@ " << left << setw(20) << name[j] << setw(10) << doneScore[j] << "   @" << endl;
    }

    gotoxy(x, y++);
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
}
int find_max(int index, int doneScore[], int idx)
{
    int maximum = doneScore[index];
    int returnIndex = index;

    for (int j = index + 1; j < idx; j++)
    {
        if (doneScore[j] > maximum)
        {
            maximum = doneScore[j];
            returnIndex = j;
        }
    }
    return returnIndex;
}

void sortPlayersDescending(string name[], int doneScore[], int idx)
{
    int maxIndex;
    string tempName;
    int tempScore;

    for (int i = 0; i < idx - 1; i++)
    {
        maxIndex = find_max(i, doneScore, idx);

        tempScore = doneScore[maxIndex];
        doneScore[maxIndex] = doneScore[i];
        doneScore[i] = tempScore;

        tempName = name[maxIndex];
        name[maxIndex] = name[i];
        name[i] = tempName;
    }
}
void fileSave(string fileName, string name, int score)
{
    ofstream file(fileName, ios::app);
    if (file.is_open())
    {
        file << name << endl;
        file << score << endl;
        file.close();
    }
}