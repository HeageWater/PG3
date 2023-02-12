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

		cout << "������Ȃ�1���I������Ȃ�0����͂��Ă�������" << endl;
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
	cout << "��������͂��Ă�������" << "\n" << "1:�S���Ҋ֘A�̑���" << "\n" << "2:�^�X�N�֘A�̑���" << endl;
	cin >> select;
	if (select == 1)
	{
		cout << "��������͂��Ă�������" << "\n" << "1:�S���Ғǉ�" << "\n" << "2:���O�ύX" << "\n" << "3:�N���X�ύX" << "\n" << "4:�S���ҍ폜" << "\n" << "5:�S���ҎQ��" << endl;
		cin >> select;
		if (select == 1)
		{
			std::string name;
			std::string className;

			cout << "�S���Җ�����͂��Ă�������" << endl;
			cin >> name;

			if (cin.fail())
			{
				cin.clear();
			}

			cin.ignore(1024, '\n');
			cout << "�S���N���X������͂��Ă�������" << endl;
			cin >> className;

			if (cin.fail())
			{
				cin.clear();
			}

			cin.ignore(1024, '\n');
			int addId = picManager->AddPIC(name, className);
			cout << "�ǉ����܂����BId��" << addId << "�ł�" << endl;
		}
		else if (select == 2)
		{
			int id = -1;
			std::string name;

			cout << "id��I�����Ă�������" << endl;
			picManager->PrintAllId();
			cin >> id;

			if (cin.fail())
			{
				cin.clear();
			}

			cin.ignore(1024, '\n');
			cout << "�S���Җ�����͂��Ă�������" << endl;
			cin >> name;

			if (cin.fail())
			{
				cin.clear();
			}

			cin.ignore(1024, '\n');
			picManager->SetName(id, name);
			cout << "�ύX���܂����B" << endl;
		}
		else if (select == 3)
		{
			int id = -1;
			std::string className;
			cout << "id��I�����Ă�������" << endl;
			picManager->PrintAllId();
			cin >> id;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			cout << "�S���N���X������͂��Ă�������" << endl;
			cin >> className;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			picManager->SetClass(id, className);
			cout << "�ύX���܂����B" << endl;
		}
		else if (select == 4)
		{
			int id = -1;
			cout << "id��I�����Ă�������" << endl;
			picManager->PrintAllId();
			cin >> id;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			picManager->DeletePic(id);
			cout << "�폜���܂����B" << endl;
		}
		else if (select == 5)
		{
			int id = -1;
			cout << "id��I�����Ă�������" << endl;
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
				cout << "�S���Җ�: " << ptr->name_ << endl;
				cout << "�S���N���X��: " << ptr->class_ << endl;
			}
		}
		else
		{
			cout << "�s���Ȓl�ł�" << endl;
		}

	}
	else if (select == 2)
	{
		cout << "��������͂��Ă�������" << "\n" << "1:�^�X�N�ǉ�" << "\n" << "2:�X�e�[�^�X�ύX" << "\n" << "3:���e�ύX" << "\n" << "4:�D��x�ύX" << "\n" << "5:�S���ҕύX" << "\n" << "6:�����ύX" << "\n" << "7:�^�X�N�폜" << "\n" << "8:�^�X�N�\��" << endl;
		cin >> select;
		if (select == 1)
		{
			std::string name;
			std::string content;
			std::string priority;
			std::string deadline;
			bool status;
			int picid;

			cout << "�^�X�N������͂��Ă�������" << endl;
			cin >> name;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			cout << "���e����͂��Ă�������" << endl;
			cin >> content;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			cout << "�D��x����͂��Ă�������" << endl;
			cin >> priority;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			cout << "��������͂��Ă�������" << endl;
			cin >> deadline;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			cout << "�X�e�[�^�X�󋵂�I�����Ă��������B0:������,1:����" << endl;
			cin >> status;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			cout << "�S����ID��I�����Ă�������" << endl;
			picManager->PrintAllId();
			cin >> picid;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			int addId = taskManager->AddTask(picid, name, content, priority, deadline, status);
			cout << "�ǉ����܂����BId��" << addId << "�ł�" << endl;
		}
		else if (select == 2)
		{
			int id = -1;
			bool status;
			cout << "id��I�����Ă�������" << endl;
			taskManager->PrintAllId();
			cin >> id;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			cout << "�X�e�[�^�X�󋵂�I�����Ă��������B0:������,1:����" << endl;
			cin >> status;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			taskManager->SetStatus(id, status);
			cout << "�ύX���܂����B" << endl;
		}
		else if (select == 3)
		{
			int id = -1;
			std::string content;
			cout << "id��I�����Ă�������" << endl;
			taskManager->PrintAllId();
			cin >> id;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			cout << "���e����͂��Ă�������" << endl;
			cin >> content;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			taskManager->SetContent(id, content);
			cout << "�ύX���܂����B" << endl;
		}
		else if (select == 4)
		{
			int id = -1;
			std::string priority;
			cout << "id��I�����Ă�������" << endl;
			taskManager->PrintAllId();
			cin >> id;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			cout << "�D��x����͂��Ă�������" << endl;
			cin >> priority;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			taskManager->SetPriority(id, priority);
			cout << "�ύX���܂����B" << endl;
		}
		else if (select == 5)
		{
			int id = -1;
			int picid;
			cout << "id��I�����Ă�������" << endl;
			taskManager->PrintAllId();
			cin >> id;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			cout << "�S����ID��I�����Ă�������" << endl;
			picManager->PrintAllId();
			cin >> picid;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			taskManager->SetPic(id, picManager->GetPicPtr(picid));
			cout << "�ύX���܂����B" << endl;
		}
		else if (select == 6)
		{
			int id = -1;
			std::string deadline;
			cout << "id��I�����Ă�������" << endl;
			taskManager->PrintAllId();
			cin >> id;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			cout << "��������͂��Ă�������" << endl;
			cin >> deadline;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			taskManager->SetDate(id, deadline);
			cout << "�ύX���܂����B" << endl;
		}
		else if (select == 7)
		{
			int id = -1;

			cout << "id��I�����Ă�������" << endl;
			taskManager->PrintAllId();
			cin >> id;
			if (cin.fail())
			{
				cin.clear();
			}
			cin.ignore(1024, '\n');
			taskManager->DeleteTask(id);
			cout << "�폜���܂����B" << endl;
		}
		else if (select == 8)
		{
			int id = -1;

			cout << "id��I�����Ă�������" << endl;
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
				cout << "�^�X�N��:" << " " << ptr->person_->name_ << endl;
				cout << "���e:" << " " << ptr->contents_ << endl;
				cout << "�D��x:" << " " << ptr->priority_ << endl;
				string status = ptr->status_ ? "����" : "������";
				cout << "�i��:" << " " << status << endl;
				if (ptr->person_)
				{
					cout << "�S����ID:" << " " << ptr->person_->id_ << endl;
				}
				cout << "����:" << " " << ptr->deadline_ << "�� " << endl;
			}
		}
		else
		{
			cout << "�s���Ȓl�ł�" << endl;
		}
	}
	else
	{
		cout << "�s���Ȓl�ł�" << endl;
	}
}

void Scene::End()
{
	picManager->ReadTxt();
	taskManager->OutPut();
}