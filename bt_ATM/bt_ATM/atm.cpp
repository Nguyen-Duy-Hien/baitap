#include"atm.h"

vector<account> list;

    void account::create_account()
	{
		system("CLS");
		cout << "\nMoi nhap tai khoan: ";
		cin >> username;
		cout << "\nMoi nhap mat khau: ";
		cin >> password;
	}
	void account::show_account()
	{
		cout << "Ten tai khoan: " << username << endl;
		cout << "So du: " << balance << endl;
	}
	string account::get_username()
	{
		return username;
	}
	void account::set_username(string username)
	{
		this->username = username;
	}
	string account::get_password()
	{
		return password;
	}
	void account::set_password(string password)
	{
		this->password = password;
	}
	void account::set_balance(long int n)
	{
		this->balance = n;
	}
	long int account::get_balance()
	{
		return balance;
	}



void menu(ATM &atm)
{
	int choose;
	do
	{
		system("CLS");
		cout << "======================\n";
		cout << "     ATM-Trang chu    \n";
		cout << "======================\n";
		cout << "1. Dang nhap.\n";
		cout << "2. Dang ky.\n";
		cout << "3. Danh sach tai khoan.\n";
        cout << "4. Nap tien vao ATM.\n";
        cout << "5. Thong tin ATM. \n";
		cout << "6. Thoat\n";
		cin >> choose;
		switch (choose)
		{
		case 1:
			log_in(atm);

			break;
		case 2:
			sign_up();
			break;
        case 3:
            list_account();
            break;
        case 4:
            transfer_to_ATM(atm);
            break;
        case 5:
            shown_ATM(atm);
            break;
		case 6:
			exit(0);
		}
	} while (choose != 6);
}


void log_in(ATM &atm)
{
	system("CLS");
	string username;
	string password;
	account acc;
	fstream inFile;
    if (list.size() < 1)
    {
        cout<<"Ban khong co tai khoan nao trong ATM\n";
        cout<<"Moi ban dang ky tai khoan\n";

        sign_up();
    }
    else
    {
        bool check = false;
        int count = 0;
        while(count < 5){
            cout<<"Tai khoan: ";
            cin>>username;
            cout<<"Mat khau: ";
            cin>>password;
            for (int i = 0; i < list.size(); i++)
            {
                if (username == list[i].get_username() && password == list[i].get_password())
                {

                    acc = find_account(username);
                    cout << "Ban dang nhap thanh cong!\n";
                    check = true;
                    system("pause");
                    account_menu(acc, atm);
                    break;
                }
            }
            count++;
            if (check)
            {
                break;
            }
            else if (!check && count < 5)
            {
                cout<<"ban nhap sai. Moi ban nhap lai!"<<endl;
            }
            else if (!check && count == 5)
            {
                cout<<"ban nhap sai 5 lan. Tai khoan cua ban bi khoa!"<<endl;
                system("pause");
            }
        }
    }
}



void sign_up()
{

    account acc;
    string username;
    string password;
    bool check = true;

    cout <<"Moi ban nhap tai khoan: ";
    cin >> username;
    for (int i = 0;i < list.size(); i++)
    {
        if (username == list[i].get_username())
        {
            cout<<"tai khoan da ton tai!"<<endl;
            check = false;
            sign_up();
            break;
        }
    }
    if (check == true)
    {
        cout << "Moi ban nhap mat khau: ";
        cin >> password;
        cout << "Ban tao thanh cong tai khoan!"<<endl;
        acc.set_username(username);
        acc.set_password(password);
        acc.set_balance(10000);
        list.push_back(acc);
        ofstream out("account.txt", ios::app);
        out<< acc.get_username() <<" "<<acc.get_balance()<<" ";
        system("pause");
    }
}

void list_account()
{
    for (int i = 0; i < list.size(); i++)
    {
        list[i].show_account();

    }
    system("pause");
}

account find_account(string username)
{
    for (int i = 0; i < list.size(); i++)
    {
        if (username == list[i].get_username())
        {
            return list[i];
        }
    }
}


void transfer_to_ATM(ATM &atm)
{

    int price10k;
    int price20k;
    int price50k;
    int price100k;
    int price200k;
    int price500k;
    cout<<"Nhap tien chuyen vao ATM"<<endl;
    cout<<"So to 10000VND la: ";
    cin>>price10k;
    atm.price10k = price10k + atm.price10k;
    cout<<"\nSo to 20000VND la: ";
    cin>>price20k;
    atm.price20k = price20k + atm.price20k;
    cout<<"\nSo to 50000VND la: ";
    cin>>price50k;
    atm.price50k = price50k + atm.price50k;
    cout<<"\nSo to 100000VND la: ";
    cin>>price100k;
    atm.price100k = price100k + atm.price100k;
    cout<<"\nSo to 200000VND la: ";
    cin>>price200k;
    atm.price200k = price200k + atm.price200k;
    cout<<"\nSo to 500000VND la: ";
    cin>>price500k;
    atm.price500k = price500k + atm.price500k;
}
void shown_ATM(ATM atm)
{
    cout<<"Tien trong ATM: "<<endl;
    cout<<"So to 10000VND la: "<<atm.price10k;

    cout<<"\nSo to 20000VND la: "<<atm.price20k;

    cout<<"\nSo to 50000VND la: "<<atm.price50k;

    cout<<"\nSo to 100000VND la: "<<atm.price100k;

    cout<<"\nSo to 200000VND la: "<<atm.price200k;

    cout<<"\nSo to 500000VND la: "<<atm.price500k;

    cout<<"\nTong so tien trong ATM la: "<<total_money_ATM(atm)<<"VND"<<endl;
    system("pause");
}

long int total_money_ATM (ATM atm)
{
    return atm.price10k*10000 + atm.price20k * 20000 + atm.price50k * 50000 + atm.price100k * 100000 + atm.price200k * 200000 + atm.price500k * 500000;
}


char *now()
{
    time_t n = time(NULL);
    char *timenow = ctime(&n);
    return timenow;
}

void account_menu(account &acc, ATM &atm)
{
	int op;
	long int n;
	string username2;
	do
	{
		system("CLS");

		cout << "\nSo du hien tai: " << acc.get_balance() << " dong.\n";
		cout << "\n1. Rut tien.\n";
		cout << "2. Nap tien.\n";
		cout << "3. Chuyen tien.\n";
		cout << "4. Xem lich su.\n";
		cout << "5. Dang xuat.\n";
		cin >> op;
		switch (op)
		{
		case 1:
		    {
            system("CLS");
			cout << "So tien hien tai cua ban la " <<acc.get_balance()<<"VND"<<endl;
			cout << "So tien hien tai trong cay ATM la "<< total_money_ATM(atm)<<"VND"<<endl;
            //cout << "\nSo tien nho nhat rut duoc trong cay ATM la " << price_min(atm) << " VND" << endl;
            rut_tien1(acc, atm);

            system("pause");
			break;
		    }

		case 2:
            system("CLS");
            deposit(acc);
            break;
        case 3:
            {
                if (list.size() < 2)
                {
                    system("CLS");
                    cout<<"Trong ATM it nhat phai co 2 tai khoan ban moi chuyen tien duoc."<<endl;
                    int choose1;
                    do
                    {
                        cout<<"1. dang ky them tai khoan."<<endl;
                        cout<<"2. thoat"<<endl;
                        cin>>choose1;
                        switch(choose1)
                        {
                        case 1:
                            {
                                sign_up();
                                cout << "Nhap tai khoan nguoi nhan: ";
                                cin >> username2;
                                account acc2 = find_account(username2);
                                cout << "\nNhap so tien muon chuyen: ";
                                cin >> n;
                                if (n > acc.get_balance())
                                {
                                    cout << "\nSo du cua ban khong du de thuc hien giao dich!\n";
                                    choose1 = 2;
                                    system("pause");
                                }
                                else
                                {
                                    transfer_account(acc, acc2, n);
                                    choose1 = 2;
                                }
                                break;
                            }

                        case 2:
                            break;
                        }
                    }while(choose1 != 2);

                }
                else
                {
                    system("CLS");
                    cout << "Nhap tai khoan nguoi nhan: ";
                    cin >> username2;
                    account acc2 = find_account(username2);
                    cout << "\nNhap so tien muon chuyen: ";
                    cin >> n;
                    if (n > acc.get_balance())
                    {
                        cout << "\nSo du cua ban khong du de thuc hien giao dich!\n";
                    }
                    else
                    {
                        transfer_account(acc, acc2, n);
                    }
                    break;
                }
                break;
            }
        case 4:
            history();
            system("pause");
            break;
        case 5:
            cout<<acc.get_balance();
            system("pause");
            menu(atm);
		}

	} while (op != 5);
}
void rut_tien1 (account &acc, ATM &atm)
{
    long int n;
    cout<<"Nhap so tien ban muon rut: ";
    cin>>n;
    rut_tien2(acc, atm, n);
}
void rut_tien2 (account &acc, ATM &atm, long int n )
{
    if (n > total_money_ATM(atm))
    {
        cout<<"\nSo tien ban nhap lon hon so tien trong ATM"<<endl;
        int choose1;
        do
        {

            cout<<"1. nhap lai so tien."<<endl;
            cout<<"2. gui them tien vao ATM."<<endl;
            cout<<"3. thoat"<<endl;
            cin>>choose1;
            switch(choose1)
            {
            case 1:
                rut_tien1(acc, atm);
                choose1 = 3;
                break;
            case 2:
                transfer_to_ATM(atm);
                rut_tien2(acc, atm, n);
                choose1 = 3;
                break;
            case 3:
                break;
            }

        }while(choose1 != 3);

    }
    else if (n > acc.get_balance())
    {
       cout<<"so tien ban nhap lon hon so tien trong tai khoan"<<endl;
       int choose1;
       do
        {

            cout<<"1. nhap lai so tien."<<endl;
            cout<<"2. gui them tien vao tai khoan."<<endl;
            cout<<"3. thoat"<<endl;
            cin>>choose1;
            switch(choose1)
            {
            case 1:
                rut_tien1(acc, atm);
                choose1 = 3;
                break;
            case 2:
                deposit(acc);
                rut_tien2(acc, atm, n);
                choose1 = 3;
                break;
            case 3:
                break;
            }

        }while(choose1 != 3);
    }
    else
    {
        windraw(acc, n, atm);
    }
}
void deposit(account &acc)
{
    long int n;
	cout << "Nhap so tien muon nap: ";
	cin >> n;
	acc.set_balance(acc.get_balance() + n);
	cout<< "\nso du tai khoan cua ban sau khi nap la: "<<acc.get_balance()<<"VND"<<endl;
	system("pause");
}

void transfer_account(account &acc, account&acc2, long int n)
{
    acc2.set_balance(acc2.get_balance() + n);

    acc.set_balance(acc.get_balance() - n);
}



int price_min(ATM atm)
{
    if(atm.price10k != 0){return 10000;}
    if(atm.price20k != 0){return 20000;}
    if(atm.price50k != 0){return 50000;}
    if(atm.price100k != 0){return 100000;}
    if(atm.price200k != 0){return 200000;}
    if(atm.price500k != 0){return 500000;}
    return 0;
}

void history()
{
    ifstream history_windraw("lich_su_rut_tien.txt");
    string windraw;
    while (getline(history_windraw, windraw))
    {
        cout<< windraw <<endl;
    }
}

void windraw(account &acc, long int n, ATM &atm)
{
    vector<int> list_number_moneyATM;
    list_number_moneyATM.push_back(atm.price500k);
    list_number_moneyATM.push_back(atm.price200k);
    list_number_moneyATM.push_back(atm.price100k);
    list_number_moneyATM.push_back(atm.price50k);
    list_number_moneyATM.push_back(atm.price20k);
    list_number_moneyATM.push_back(atm.price10k);


    vector<int> list_number_money;
    int price[] = {500000, 200000, 100000, 50000, 20000, 10000};
    long int money = n;
    int number_money = 0;

    for (int i = 0; i < 6; i++)
    {
        number_money += money / price[i];
        list_number_money.push_back(number_money);
        money %= price[i];
        number_money = 0;
    }
    bool check = true;
    for (int i = 0; i < 6; i++)
    {
        if (list_number_money[i] > list_number_moneyATM[i])
        {
            cout<<"ATM khong co du so to tien de thuc hien giao dich!"<<endl;
            check = false;
            break;
        }
    }
    if (check == true)
    {
        cout<<"Ban rut tien thanh cong. so tien ban nhan duoc la:\n";
        acc.set_balance(acc.get_balance() - n);
        atm.price500k = atm.price500k - list_number_money[0];
        atm.price200k = atm.price200k - list_number_money[1];
        atm.price100k = atm.price100k - list_number_money[2];
        atm.price50k = atm.price50k - list_number_money[3];
        atm.price20k = atm.price20k - list_number_money[4];
        atm.price10k = atm.price10k - list_number_money[5];

        ofstream history_windraw("lich_su_rut_tien.txt", ios::app);
        history_windraw << now() << "Tai khoan " << acc.get_username() << " da rut:" << endl;
        if(list_number_money[0] != 0){history_windraw << "- " << list_number_money[0] << " to 500000VND" << endl;}
        if(list_number_money[1] != 0){history_windraw << "- " << list_number_money[1] << " to 200000VND" << endl;}
        if(list_number_money[2] != 0){history_windraw << "- " << list_number_money[2] << " to 100000VND" << endl;}
        if(list_number_money[3] != 0){history_windraw << "- " << list_number_money[3] << " to 50000VND" << endl;}
        if(list_number_money[4] != 0){history_windraw << "- " << list_number_money[4] << " to 20000VND" << endl;}
        if(list_number_money[5] != 0){history_windraw << "- " << list_number_money[5] << " to 10000VND" << endl;}

        for (int i = 0; i < 6; i++)
        {
            if (list_number_money[i] != 0)
            {
                cout<<list_number_money[i]<<" to " << price[i] <<"VND"<<endl;
            }
        }
        history_windraw.close();
    }
}

