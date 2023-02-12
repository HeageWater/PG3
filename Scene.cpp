#include "Scene.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

Scene* Scene::GetInstance()
{
	static Scene instance;
	return &instance;
}

void Scene::Act()
{
	Initialize();

	while (true)
	{
		int returnFlag = true;

		Update();

		cout << "続けるなら1を終了するなら0を入力してください" << endl;
		cin >> returnFlag;

		if (!returnFlag)
		{
			End();
			break;
		}
	}
}

void Scene::Initialize()
{
	picManager->WriteTxt();
	taskManager->InPut();
}

void Scene::Update()
{
	int select = -1;
	cout << "数字を入力してください" << "\n" << "1:担当者関連の操作" << "\n" << "2:タスク関連の操作" << endl;
	cin >> select;
	if (select == 1)
	{
		cout << "数字を入力してください" << "\n" << "1:担当者追加" << "\n" << "2:名前変更" << "\n" << "3:クラス変更" << "\n" << "4:担当者削除" << "\n" << "5:担当者参照" << endl;
		cin >> select;
		if (select == 1)
		{
			std::string name;
			std::string className;

			cout << "担当者名を入力してください" << endl;
			cin >> name;

			if (cin.fail())
			{
				cin.clear();
			}

			cin.ignore(1024, '\n');
			cout << "担当クラス名を入力してください" << endl;
			cin >> className;

			if (cin.fail())
			{
				cin.clear();
			}

			cin.ignore(1024, '\n');
			int addId = picManager->AddPIC(name, className);
			cout << "追加しました。Idは" << addId << "です" << endl;
		}
		else if (select == 2)
		{
			int id = -1;
			std::string name;

			cout << "idを選択してください" << endl;
			picManager->PrintAllId();
			cin >> id;

			if (cin.fail())
			{
				cin.clear();
			}

			cin.ignore(1024, '\n');
			cout << "担当者名を入力してください" << endl;
			cin >> name;

			if (cin.fail())
			{
				cin.clear();
			}

			cin.ignore(1024, '\n');
			picManager->SetName(id, name);
			cout << "変更しました。" << endl;
		}
		else if (select == 3)
		{
			int id = -1;
			std::string className;
			cout << "idを選択してください" << endl;
			picManager->PrintAllId();
			cin >> id;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			cout << "担当クラス名を入力してください" << endl;
			cin >> className;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			picManager->SetClass(id, className);
			cout << "変更しました。" << endl;
		}
		else if (select == 4)
		{
			int id = -1;
			cout << "idを選択してください" << endl;
			picManager->PrintAllId();
			cin >> id;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			picManager->DeletePic(id);
			cout << "削除しました。" << endl;
		}
		else if (select == 5)
		{
			int id = -1;
			cout << "idを選択してください" << endl;
			picManager->PrintAllId();
			cin >> id;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			Person* ptr = picManager->GetPicPtr(id);
			if (ptr)
			{
				cout << "ID: " << ptr->id_ << endl;
				cout << "担当者名: " << ptr->name_ << endl;
				cout << "担当クラス名: " << ptr->class_ << endl;
			}
		}
		else
		{
			cout << "不正な値です" << endl;
		}

	}
	else if (select == 2)
	{
		cout << "数字を入力してください" << "\n" << "1:タスク追加" << "\n" << "2:ステータス変更" << "\n" << "3:内容変更" << "\n" << "4:優先度変更" << "\n" << "5:担当者変更" << "\n" << "6:期限変更" << "\n" << "7:タスク削除" << "\n" << "8:タスク表示" << endl;
		cin >> select;
		if (select == 1)
		{
			std::string name;
			std::string content;
			std::string priority;
			std::string deadline;
			bool status;
			int picid;

			cout << "タスク名を入力してください" << endl;
			cin >> name;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			cout << "内容を入力してください" << endl;
			cin >> content;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			cout << "優先度を入力してください" << endl;
			cin >> priority;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			cout << "期日を入力してください" << endl;
			cin >> deadline;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			cout << "ステータス状況を選択してください。0:未完了,1:完了" << endl;
			cin >> status;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			cout << "担当者IDを選択してください" << endl;
			picManager->PrintAllId();
			cin >> picid;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			int addId = taskManager->AddTask(picid, name, content, priority, deadline, status);
			cout << "追加しました。Idは" << addId << "です" << endl;
		}
		else if (select == 2)
		{
			int id = -1;
			bool status;
			cout << "idを選択してください" << endl;
			taskManager->PrintAllId();
			cin >> id;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			cout << "ステータス状況を選択してください。0:未完了,1:完了" << endl;
			cin >> status;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			taskManager->SetStatus(id, status);
			cout << "変更しました。" << endl;
		}
		else if (select == 3)
		{
			int id = -1;
			std::string content;
			cout << "idを選択してください" << endl;
			taskManager->PrintAllId();
			cin >> id;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			cout << "内容を入力してください" << endl;
			cin >> content;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			taskManager->SetContent(id, content);
			cout << "変更しました。" << endl;
		}
		else if (select == 4)
		{
			int id = -1;
			std::string priority;
			cout << "idを選択してください" << endl;
			taskManager->PrintAllId();
			cin >> id;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			cout << "優先度を入力してください" << endl;
			cin >> priority;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			taskManager->SetPriority(id, priority);
			cout << "変更しました。" << endl;
		}
		else if (select == 5)
		{
			int id = -1;
			int picid;
			cout << "idを選択してください" << endl;
			taskManager->PrintAllId();
			cin >> id;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			cout << "担当者IDを選択してください" << endl;
			picManager->PrintAllId();
			cin >> picid;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			taskManager->SetPic(id, picManager->GetPicPtr(picid));
			cout << "変更しました。" << endl;
		}
		else if (select == 6)
		{
			int id = -1;
			std::string deadline;
			cout << "idを選択してください" << endl;
			taskManager->PrintAllId();
			cin >> id;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			cout << "期日を入力してください" << endl;
			cin >> deadline;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			taskManager->SetDate(id, deadline);
			cout << "変更しました。" << endl;
		}
		else if (select == 7)
		{
			int id = -1;

			cout << "idを選択してください" << endl;
			taskManager->PrintAllId();
			cin >> id;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			taskManager->DeleteTask(id);
			cout << "削除しました。" << endl;
		}
		else if (select == 8)
		{
			int id = -1;

			cout << "idを選択してください" << endl;
			taskManager->PrintAllId();
			cin >> id;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			Task* ptr = taskManager->GetTask(id);
			if (ptr)
			{
				cout << "ID:" << " " << ptr->id_ << endl;
				cout << "タスク名:" << " " << ptr->person_->name_ << endl;
				cout << "内容:" << " " << ptr->contents_ << endl;
				cout << "優先度:" << " " << ptr->priority_ << endl;
				string status = ptr->status_ ? "完了" : "未完了";
				cout << "進捗:" << " " << status << endl;
				if (ptr->person_)
				{
					cout << "担当者ID:" << " " << ptr->person_->id_ << endl;
				}
				cout << "期限:" << " " << ptr->deadline_ << "月 " << endl;
			}
		}
		else
		{
			cout << "不正な値です" << endl;
		}
	}
	else
	{
		cout << "不正な値です" << endl;
	}
}

void Scene::End()
{
	picManager->ReadTxt();
	taskManager->OutPut();
}