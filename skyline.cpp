////////////////////////**SOURCE CODE**/////////////////
///////////////////////**SKYLINE**//////////////////////
#
include < fstream.h > #include < graphics.h > #include < conio.h > #include < dos.h > #include < stdio.h > #include < stdlib.h > #include < string.h > #include < iomanip.h >

    int gdriver = DETECT, gmode, flag = 0, t_cl = 15, b_cl = 9;
fstream fp, fc, f3, f4; //objects of data file
const int sz = 5;
long ll;
char choice, ln = 240;

void box(int x_cor) {
    for (int x = 0; x < 12; x++) {
        gotoxy(x_cor, 7 + x);
        cout << char(186);
    }
}

void ft_array(char a[], int u) //floating array
    {
        for (int i1 = 0; i1 < strlen(a); i1++) {
            delay(u);
            cout << a[i1];
        }
    }

int comma(int gtol) {
    if (gtol >= 10000) //to provide comma's for grandtotal
    {
        cout << gtol / 1000 << ",";
        gtol = gtol % 1000;
    } else if (gtol >= 1000) {
        cout << gtol / 1000 << ",";
        gtol = gtol % 1000;
    } else {}
    return gtol;
}

void design(int utm, char dz) {
    for (int ii = 0; ii < utm; ii++)
        cout << char(dz);
}

void draw(int x1, int y1, int x2, int y2, char str[]) //TAB BUTTONS
    {
        rectangle(x1, y1, x2, y2);
        outtextxy(x1 + 20, y1 + 15, str);
    }

void load(int dly, int rpt, char ld_str[], int b_cl1 = 9) //LOADING WINDOW
    {
        initgraph( & gdriver, & gmode, "c:\\turbo\\bgi");
        int d_tm = 150, x_xis = getmaxx() / 2, y_xis = 260, m_xis = 260, m_yis = 310, il, jl, kl;
        delay(800);
        for (jl = 0; jl < dly; jl++) { //for j
            setbkcolor(b_cl1);
            for (kl = 1; kl <= rpt; kl++) { //for k
                for (il = 0; il < 30; il += 10) { //for i
                    rectangle(190, 230, 450, 340); //inner window
                    rectangle(188, 228, 452, 342); //outer window
                    rectangle(m_xis, m_yis, m_xis + 120, m_yis + 20);
                    outtextxy(m_xis + 10, m_yis + 7, ld_str);

                    if (kl % 2 != 0) {
                        bar(x_xis + il, y_xis - il, x_xis - 5 + il, y_xis + 10 + il);
                    } //LOADING BARS
                    else if (kl % 2 == 0) {
                        bar(x_xis + 20 - il, y_xis - il, x_xis + 15 - il, y_xis + 10 + il);
                    }

                    delay(d_tm);

                } //for i
                cleardevice();
            } //for j
        } //for k
        closegraph();
    } //load

void input(int l, int m, char in []) {
    delay(800);
    gotoxy(l, m);
    cout << "                ";
    gotoxy(l + 1, m);
    gets( in );
}

//////////////////////
////****LOGIN CLASS***//
//////////////////////

class airline {
    public: char passname[20], passcode[20];
    airline();
};

void airline::airline() //APP STARTER PAGE
    {

        initgraph( & gdriver, & gmode, "c:\\turbo\\bgi");
        gotoxy(18, 28);
        setbkcolor(CYAN);
        outtextxy(200, 420, "[ NOTE :Enter On Each Tab To Fill Details ]");
        line(350, 70, 350, 400);
        line(352, 70, 352, 400);

        delay(2000);
        draw(168, 178, 302, 262, " ");
        draw(190, 180, 280, 260, " ");
        delay(1500);
        setcolor(RED);
        draw(180, 180, 290, 260, "");
        settextstyle(10, 0, 5);
        outtextxy(196, 160, "sA");
        setcolor(WHITE);
        for (int m = 0; m < 77; m += 11) {
            delay(500);
            arc(173, 187 + m, 360, 0, 3);
            arc(297, 187 + m, 360, 0, 3);
        }
        delay(800);
        settextstyle(0, 0, 1);

        draw(400, 180, 555, 210, "Enter User I-D");
        draw(400, 230, 555, 260, "Enter Password");
        getch();
        input(52, 13, passname);
        input(53, 16, passcode);

    }

/////////////////////////////////////////

void plane() //FLYING PLANE USING GRAPHICS
    {
        int gdriver = DETECT, gmode, errorcode;
        initgraph( & gdriver, & gmode, "c:\\turbo\\bgi");
        delay(1500);
        for (int z1 = 10; z1 <= 350; z1 += 10) {
            delay(400);
            cleardevice();

            setbkcolor(LIGHTBLUE);
            setcolor(LIGHTGRAY);

            for (int z4 = 0; z4 < 6; z4++) {
                line(630 - z1 + z4, 110, 630 - z1 + z4, 300);
                line(630 - z1 - z4, 110, 530 - z1 - z4, 300);
                line(525 - z1 + z4, 300 + z4, 635 - z1 + z4, 300 + z4);
            }

            line(630 - z1, 230, 675 - z1, 230);
            settextstyle(2, 0, 7);
            outtextxy(675 - z1, 215, "o");
            setcolor(RED);
            settextstyle(7, 0, 1);
            outtextxy(628 - z1, 91, "o");
            for (int z2 = 0, z3 = 0; z2 < 6; z2 += 1, z3 += 2) {
                setcolor(BROWN);
                line(584 - z1 - z2, 200 + z3, 628 - z1, 200 + z3);
                setcolor(GREEN);
                line(563 - z1 - z2, 240 + z3, 628 - z1, 240 + z3);
            }
            for (z4 = 0, z3 = 0; z4 < 50; z4 += 2, z3++) {
                setcolor(LIGHTGRAY);
                line(555 - z3 - z1, 252 + z4, 629 - z1, 252 + z4); //3
            }
            for (z4 = 0, z3 = 0; z4 < 27; z4 += 2, z3++) {
                setcolor(LIGHTGRAY);
                line(576 - z3 - z1, 212 + z4, 629 - z1, 212 + z4); //2
            }
            for (z4 = 0, z3 = 0; z4 < 96; z4 += 2, z3++) {
                setcolor(LIGHTGRAY);
                line(625 - z3 - z1, 115 + z4, 629 - z1, 115 + z4); //1
            }

            setcolor(LIGHTGREEN);

            arc(700 - z1, 205, 30, 190, 30);
            arc(748 - z1, 170, 220, 40, 30);

            arc(700 - z1, 265, 30, 165, 30);
            arc(748 - z1, 230, 210, 0, 30);

            line(670 - z1, 205, 670 - z1, 258);
            line(770 - z1, 151, 770 - z1, 190);

            line(778 - z1, 175, 778 - z1, 230);
            settextstyle(5, 0, 2);
            outtextxy(690 - z1, 197, "SKYLINE");
            if (kbhit()) {
                break;
            }
        }
        getch();
        closegraph();
    }

//////////////////////////////////////
///*******ADMINISTRATOR CLASS*******////
//////////////////////////////////////

class ACC {
    char city[20];
    public: int cost;

    void enter() //TO ENTER CITY DETAILS
        {
            cout << "\n\n";
            cout << "Enter Fare : ";
            cin >> cost;
        }

    void show() //TO SHOW CITY DETAILS
        {
            cout << "\n\n";
            cout << setw(36) << city << " <" << ln << ln << ln << ln << "> " << cost;
        }
    int check_city(char c1[], char c2[]) {
        int value = 0;
        if (strcmp(city, c1) == 0 || strcmp(city, c2) == 0) {
            value = 0;
        } else {
            value = 1;
        }
        return value;
    }

    void admnln();
    void show_det();
    void add_det();
    void modify_det();
    void delete_det();
    void EXIT();
}
FL;

/////////////////////////////////////////////////////////////

void ACC::add_det() //ADDING CITY DETAILS IN DATABASE
    {
        int yes = 0;
        const int lth = 10,
            bth = 15,
            x_cor = 33,
            y_cor = 5;
        char choice[lth], list[lth][bth] = {
            "DELHI",
            "SIKKIM",
            "JAIPUR",
            "MANIPUR",
            "CHENNAI",
            "MUMBAI",
            "PUNE",
            "MANALI",
            "BANGLORE",
            "KOLKATA"
        };
        int i, j, i1;

        gotoxy(38, 24);
        cout << "=>=>Click [y] Against The City To Be Added";
        gotoxy(x_cor - 3, y_cor - 2);
        cout << "CODE   CITY";

        for (i = 0; i < lth; i++) {
            gotoxy(x_cor - 2, y_cor + i);
            cout << setw(2) << i + 1 << "   " << list[i];
            gotoxy(x_cor + 11, y_cor + i);
            cout << "[ ]";
            gotoxy(x_cor + 12, y_cor + i);
            choice[i] = getch();
            if (choice[i] == 'y' || choice[i] == 'Y') {
                cout << " ";
                yes++;
            } else {
                cout << char(1);
            }
        }
        getch();
        gotoxy(30, 20);
        delay(500);
        ft_array(" Getting List Ready ... .. .", 250);
        delay(500);
        clrscr();
        if (yes == 0) {
            cout << "Nothing to Upload";
            ft_array("... .. .", 300);
        } else {
            f3.open("prc.dat", ios:: in | ios::binary);
            while (f3.read((char * ) & FL, sizeof(FL))) {
                for (i1 = 0; i1 < lth; i1++) {
                    if ((strcmp(city, list[i1]) == 0) && (choice[i1] == 'y' || choice[i1] == 'Y')) {
                        cout << "==>=>>City [" << list[i1] << "] already exist";
                        cout << "\n\nYou can't add the same city number of times";
                        cout << "\n\nIf You Want To Modify Details Press [MODIFY] Tab In Main Menu";
                        getch();
                        load(2, 4, "  MAIN MENU");
                        f3.close();
                        admnln();
                        break;
                    }
                }
            }
            f3.close();

            f3.open("prc.dat", ios::app | ios::binary);
            for (i = 0; i < lth; i++) {
                if (choice[i] == 'y' || choice[i] == 'Y') {
                    strcpy(city, list[i]);
                    cout << "\n" << "CITY \t> " << city;
                    enter();
                    f3.write((char * ) & FL, sizeof(FL));
                }
            }
            f3.close();
            load(2, 4, "Uploading . .");
        }
        delay(1000);
    }

//////////////////////////////////////////////////

void ACC::show_det() //SHOWING CITY DETAILS USING BINARY FILE

{
    f3.open("prc.dat", ios:: in | ios::binary);
    delay(1200);
    cout << "\n" << setw(38) << "CITY <" << ln << ln << ln << ln << "> FARE" << "\n ";
    design(78, 220);
    while (!f3.eof()) {
        f3.read((char * ) & FL, sizeof(FL));
        if (f3.eof()) {
            break;
        }
        delay(300); {
            FL.show();
        }
    }
    f3.close();
    getch();
}

//////////////////////////////////////////////////

void ACC::modify_det() //MODIFING CITY DETAILS ON DATA FILE

{
    char name[10];
    int found = 0;
    cout << "\n\t\tUPDATE City Details.... ";
    cout << "\n\nEnter City Name : ";
    gets(name);
    f3.open("prc.dat", ios:: in | ios::out);

    while (!f3.eof()) {
        ll = f3.tellg();
        f3.read((char * ) & FL, sizeof(FL));
        if (strcmp(name, city) == 0) {
            show();
            cout << "\nEnter The New Details of City" << endl;
            enter();
            f3.seekg(ll);
            f3.write((char * ) & FL, sizeof(FL));
            found = 1;
            load(2, 4, "Updating . . .");
            break;
        }
    }

    f3.close();
    if (found == 0) {
        cout << "\n\n\n\n\t\t\t Record Not Found ";
        getch();
    }
}

//////////////////////////////////////////////////

void ACC::delete_det() //DELETING CITY DETAILS FRON DATABASE

{
    char name[20];
    int flag = 0;
    f3.open("prc.dat", ios:: in | ios::out);
    f4.open("Tempo.dat", ios::out);
    cout << "\n\t\t::::::DELETE CITY::::::";
    cout << "\n\nEnter The City To Be Deleted : ";
    cin >> name;
    f3.seekg(0, ios::beg);
    while (!f3.eof()) {
        f3.read((char * ) & FL, sizeof(FL));
        if (f3.eof()) {
            break;
        }
        if (strcmp(city, name) == 0)
            flag = 1;
        else {
            f4.write((char * ) & FL, sizeof(FL));
        }
    }

    f4.close();
    f3.close();
    remove("prc.dat");
    rename("Tempo.dat", "prc.dat");
    if (flag == 1) {
        load(1, 4, "Deleting . . .");
    } else {
        cout << "\n\n\a\aRecord not found";
        getch();
    }
}

/////////////////////////////

void ACC::EXIT() {
    cout << "\n\n\t\tDelete OR Save File (d/s) : ";
    cin >> choice;
    delay(100);
    if (choice == 'd' || choice == 'D') {
        load(3, 2, "Deleting . . .");
        remove("prc.dat");
        remove("GUEST.dat");
    } else {
        load(3, 2, " Saving . . .");
    }
    load(2, 4, "Exiting . . .");
    exit(0);
}

///////////////////////
///////USER CLASS////////
////////////////////////

struct peo_det //PERSONAL RECORD OF USERS
{
    int age[sz];
    char name[sz][10], gen[sz][7], passnum[sz][8];
};

struct calender //TO KEEP RECORD OF BOOKING DATE
{
    int date, month;
};

class Guest {
    int numppl, seat, t_code, num, fare, phone;
    char dep[20], arr[20], cabin, family[10], option, GENDER;
    calender C;
    peo_det D;

    public:

        int givecode() {
            randomize();
            t_code = (rand() % 987) + 123;
            return random(t_code);
        }

    int give(int, int);
    int bill(char[], char[]);
    void peo_ent(char);
    void trv_ent();
    void peo_quer();
    void trv_quer();
    void enter();
    void query();
    void modfy(int, int);
    void cancl(int, int);
    void guestln();
    void guest_det(char);
}
G;

///////////////////////////////////////

void ACC::admnln() {
    for (;;) {
        textcolor(t_cl);
        textbackground(b_cl);
        clrscr();
        cout << "\n\t\t\t::::::ADMINISTRATOR MENU::::::";
        cout << "\n\t\t\t      ~~~~~~~~~~~~~~~~~~      ";
        cout << "\n\n\t\t1.Add\n\n\t\t2.Show\n\n\t\t3.Update\n\n\t\t4.Delete";
        cout << "\n\n\t\t5.People Details\n\n\t\t6.From<-->To\n\n\t\t\t0.EXIT";
        choice = getch();
        clrscr();

        switch (choice) {
        case '1':
            add_det();
            break;
        case '2':
            show_det();
            break;
        case '3':
            modify_det();
            break;
        case '4':
            delete_det();
            break;
        case '5':
            G.guest_det('S');
            break;
        case '6':
            G.guest_det('F');
            break;
        case '0':
            EXIT();
            break;
        default:
            cout << "\n\a\aWrong Choice";
        }
    }
}

//////////////////////////////////////

int Guest::bill(char dep[], char arr[]) //GENERATING BILL ACCORDING TO PLACE

{
    int cost = 0;
    fc.open("prc.dat", ios:: in | ios::binary);
    while (!fc.eof()) {
        fc.read((char * ) & FL, sizeof(FL));
        if (fc.eof()) {
            break;
        }
        if (FL.check_city(dep, arr) == 0) {
            cost += FL.cost;
        }
    }
    fc.close();
    return cost;
}

/////////////////////////////////////////////

void Guest::guestln() //RESERVATION RAGE FOR USER

{
    int opt;
    for (;;) {
        load(2, 4, "  ||SKYLINE||");
        delay(1500);
        textbackground(b_cl);
        textcolor(t_cl);
        clrscr();
        cout << "\n\n  ::::::WELCOME TO RESERVATION PAGE::::::";
        cout << "\n        ~~~~~~~~~~~~~~~~~~~~~~~~~~~      ";
        cout << "\n\n\t\t\t Please select a kind of user:";
        cout << "\n\n\t1.New User\n\n\t2.Existing User\n\n\t\t0.Exit";
        opt = getch();

        switch (opt) {
        case '1':
            G.enter();
            break;
        case '2':
            G.query();
            break;
        case '0':
            load(2, 4, "EXITING . . .");
            exit(0);
            break;

        default:
            cout << "Wrong Choice :";
        }
    }
}

//////////////////////////////////////////////

int Guest::give(int cn_code, int cn_phone) {
    int pass = 0;
    if ((cn_code == t_code) || (cn_phone == phone)) {
        pass = 1;
    }
    return pass;
}

//////////////ENTRY//////////////////////

void Guest::peo_ent(char word = 'E') //ADDING USER DETAILS IN DATABASE

{
    clrscr();
    num = 0;
    if (word == 'E') {
        cout << "\n\n   ::::::: PERSONAL DETAILS :::::::\n";

        cout << "\n\t\t\tFamily Name(Surname)     : ";
        cin >> family;
        cout << "\n\t\t\tRegistered No. (XXXX)    : ";
        cin >> phone;
        cout << "\n\t\tNOTE\n";
        cout << "\n     -> Your Confirmation Code : " << givecode();
        cout << "\n     -> For Future Inquiry Use The Above Code And Your Mobile No.";
        cout << "\n  \t\tConfirm Code   : ";
        cin >> t_code;
    }
    cout << "\n\n\t\t\tEnter The No of People   : ";
    cin >> numppl;
    clrscr();

    if (numppl > 0) {
        cout << "\n\t\tPlease Enter The Details of each Member : " << endl;
        for (int i = 0; i < numppl; i++) {
            cout << "\n\t\t<Member>" << i + 1;
            cout << "\n\t\t~~~~~~~~\n";
            cout << "\n\t\tFirst Name   : ";
            gets(D.name[i]);
            cout << "\n\t\tAge(in years): ";
            cin >> D.age[i];
            cout << "\n\t\tGender (M/F) : ";
            GENDER = getch();
            cout << GENDER;

            if (GENDER == 'm' || GENDER == 'M') strcpy(D.gen[i], "MALE");
            else if (GENDER == 'f' || GENDER == 'F') strcpy(D.gen[i], "FEMALE");
            else strcpy(D.gen[i], "????");
            step_pass: {
                gotoxy(17, 13 + 11 * i);
                cout << "Passport(7-X): ";gets(D.passnum[i]);
                if (strlen(D.passnum[i]) != 7) {
                    gotoxy(31, 13);
                    cout << "            ";
                    cprintf("-> Enter a 7 digits PASSPORT No.");
                    goto step_pass;
                } else {}
            }
            if (D.age[i] > 7) {
                num++;
            } //trav. above 7 yrs
        }
        delay(300);
        load(2, 4, "Forwarding . .");
    }

}

/////////////////QUERY/////////////////

void Guest::peo_quer() //SHOWING USER DETAILS PRESENT IN DATABASE

{
    clrscr();
    cout << "\n\t\t   ********** PERSONAL DETAILS **********";
    cout << "\n\n\t\t\tRegistered Phone Number: ";
    cout << phone;
    cout << "\n\n\t\t   Member Name   Age  Gender  Passport  Seat\n" << endl;

    for (int i = 0; i < 43; i++) {
        gotoxy(18 + i, 7);
        cout << char(205);
        gotoxy(18 + i, 18);
        cout << char(205);
    }
    int SPC = 18;
    box(SPC - 1);
    box(SPC + 14);
    box(SPC + 20);
    box(SPC + 27);
    box(SPC + 38);
    box(SPC + 43);

    for (i = 0; i < numppl; i++) {
        gotoxy(18, 8 + i);
        cout << D.name[i] << " " << family;
        gotoxy(34, 8 + i);
        cout << D.age[i];
        gotoxy(39, 8 + i);
        cout << D.gen[i];
        gotoxy(47, 8 + i);
        cout << D.passnum[i];
        gotoxy(58, 8 + i);
        cout << seat + i;
    }
    getch();
}

//////////ADMN QUERY/////////////////////////

void Guest::guest_det(char sim = 'S')

{
    char from[10], too[10];
    clrscr();
    cout << "\n\n  ";
    if (sim != 'S') {
        cout << "\t\tDepart " << char(280) << " ";
        cin >> from;
        gotoxy(45, 3);
        cout << "Arival " << char(281) << " ";
        cin >> too;
        cout << "\n\n  ";
    }
    cout << "FAMILY NAME\tREGISTERED NO.\tDEPART\tARRIVAL   DATE  CABIN      FARE\n\n";

    fp.open("GUEST.dat", ios:: in );
    while (fp.read((char * ) & G, sizeof(G))) {
        if (fp.eof()) {
            break;
        }
        if ((strcmp(from, dep) == 0 && strcmp(too, arr) == 0) || sim == 'S') {
            cout << setw(11) << family << setw(12) << phone;
            if (sim == 'S') {
                cout << setw(14) << dep << setw(10) << arr;
            } else {
                cout << " \t XXXX    XXXX   ";
            }
            cout << setw(4);
            cout << C.date << "-";
            if (C.month < 10) {
                cout << "0";
            } else {}
            cout << C.month << "   ";
            if (cabin == 'B' || cabin == 'b') {
                cout << "BUSINESS ";
            } else if (cabin == 'E' || cabin == 'e') {
                cout << "ECONOMY ";
            } else {
                cout << "??     ";
            }

            cout << comma(fare) << "\n";
            delay(300);
        }
    }
    fp.close();
    getch();
}

////////////////TRAVEL ENTRY//////////////////

void Guest::trv_ent() //TRAVELLING DETAILS FOR USER

{
    clrscr();
    cout << "\n\n\t\t\t< TRAVEL DETAILS >";
    cout << "\n\t\t\t~~~~~~~~~~~~~~~~~~";
    cout << "\n\n->Please enter the following details for your journey:\n";

    cout << "\n\t\t->Departure     : ";
    gets(dep);
    cout << "\n\t\t->Arrival       : ";
    gets(arr);
    fare = bill(dep, arr) * num;

    cout << fare;
    gotoxy(17, 12);
    cout << "->Date to Depart: ";
    cin >> C.date;
    gotoxy(37, 12);
    cout << "-";
    cin >> C.month;
    gotoxy(40, 12);
    cout << "-2015\n";
    cout << "\n\t\t->Cabin    (B)/(E): ";
    cin >> cabin;
    cout << "\n\t\t->Seat Number   : ";
    cin >> seat;
    cout << "\n\n\n\t\t\t";
    cprintf("::Press Enter::");
    getch();
    delay(400);
    load(2, 4, "Reserving . . .");
}

////////////TRAVEL QUERY/////////////

void Guest::trv_quer() {
    clrscr();
    cout << "\n\n\t\t\t< TRAVEL DETAILS >";
    cout << "\n\t\t\t~~~~~~~~~~~~~~~~~";
    cout << "\n\n->Following details for your journey:\n";
    cout << "\n\t\t->Departure     : ";
    cout << dep;
    cout << "\n\t\t->Arrival       : ";
    cout << arr;
    cout << "\n\t\t->Date to Depart: ";
    cout << C.date << "-" << C.month << "-2015";
    cout << "\n\t\t->Cabin AC/N-AC : ";
    if (cabin == 'B' || cabin == 'b') {
        cout << "BUSINESS";
    } else if (cabin == 'E' || cabin == 'e') {
        cout << "ECONOMY";
    } else {
        cout << "???";
    }
    cout << "\n\t\t->Seat Number   : ";
    for (int g = 0; g < numppl; g++) {
        cout << "<" << seat + g << "> ";
    }

    cout << "\n\t\t->Fare(Incl Tax): ";
    cout << comma(fare);
    cout << "\n\n\n\t\t   [NOTE : No Fare For Member Below 7 Years]";
}

////////////////////ENTRY//////////////////////

void Guest::enter()

{
    fp.open("GUEST.dat", ios::app | ios::binary);
    peo_ent();
    trv_ent();
    fp.write((char * ) & G, sizeof(G));
    fp.close();
}

///////////QUERY///////////////

void Guest::query()

{
    clrscr();
    char fm[10];
    int tel, cd, count = 0;
    cout << "\nEnter Registered Phone No.: ";
    cin >> tel;
    cout << "\nEnter Confirmation Code   : ";
    cin >> cd;
    cout << "\n\n\n\n\n\t\t\t";
    cprintf("::PRESS ENTER::");
    getch();
    delay(300);
    load(2, 4, "Retrieving . .");
    delay(400);
    fp.open("GUEST.dat", ios:: in | ios::binary);
    while (!fp.eof()) {
        fp.read((char * ) & G, sizeof(G));
        if (give(cd, tel) == 1) {
            count++;
            peo_quer();
            trv_quer();
            break;
        }
    }
    fp.close();

    if (count != 0) {
        cout << "\n\nSelect Further Option For Your Acknowledgement Page ";
        cout << "\n\n\t1.SUBMIT \t 2.MODIFY \t 3.CANCEL ";
        option = getch();
        switch (option) {
        case '1':
            load(2, 4, "Submitting .. .");
            break;
        case '2':
            modfy(cd, tel);
            break;
        case '3':
            cancl(cd, tel);
            break;
        default:
            cout << "Wrong Choice";
        }
    } else {
        cout << "\n\n\n\n\n\t\t\t  No Such Record";
        getch();
    }
    delay(500);
}

//////////////MODIFY/////////////////

void Guest::modfy(int cd, int tel) //MODIFING USER TRAVELLING DETAILS IN DATABASE

{
    clrscr();
    int found = 0;
    cout << "\n\t\tUPDATE Details.... ";
    fp.open("Guest.dat", ios:: in | ios::out | ios::binary);
    while (!fp.eof()) {
        ll = fp.tellg();
        fp.read((char * ) & G, sizeof(G));
        if (give(cd, tel) == 1) {
            cout << "\nEnter The New Details of Person\n";
            peo_ent('M');
            trv_ent();
            fp.seekp(ll);
            fp.write((char * ) & G, sizeof(G));
            found = 1;
            load(2, 4, "Updating . . .");
            break;
        }
    }
    fp.close();
    if (found == 0) {
        cout << "\n\n\n\t\t\t No Record To Update ";
        getch();
    }
}

////////////////CANCEL//////////////////

void Guest::cancl(int cd, int tel) //CANCELLING TICKETS

{
    clrscr();
    int flag = 0;
    fp.open("Guest.dat", ios:: in | ios::out);
    fc.open("Tempo.dat", ios::out);
    //fp.seekg(0,ios::beg);
    while (!fp.eof()) {
        fp.read((char * ) & G, sizeof(G));
        if (fp.eof()) {
            break;
        }
        if (give(cd, tel) != 1)
            fc.write((char * ) & G, sizeof(G));
        else
            flag = 1;
    }

    fc.close();
    fp.close();
    remove("Guest.dat");
    rename("Tempo.dat", "Guest.dat");
    if (flag == 1) {
        load(2, 4, "Canceling..");
    } else {
        cout << "\n\n\n\n\t\t\t  \a\aNo Such Record";
        getch();
    }
}

/////////////////////
/////////MAIN//////////
//////////////////////

void main() {
    plane(); //INVOKING APP STARTER PAGE
    airline AIR; //OBJECT OF ADMINISTRATOR CLASS

    load(2, 4, "Loading . . .", 11);

    for (;;) {
        if (strcmp(AIR.passcode, "#SKYLINE_") == 0)
            FL.admnln(); //for administrator login
        else if (strcmp(AIR.passcode, "EXIT") == 0)
            exit(0);
        else
            G.guestln(); //for guest login page
    }

}
