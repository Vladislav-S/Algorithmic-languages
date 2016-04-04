#include <iostream>
#include <string>

using namespace std;

#define SIZE 100
#define PRINT(A) cout << endl << #A << endl; 

class queue {
	int q[SIZE];
	int sloc, rloc, size;
public:
	queue();
	void qput(int val);
	int qget();
	int gsize();
};

int queue::gsize() {
	return size;
}
queue::queue()
{
	rloc = sloc = size = 0;
}

void queue::qput(int val)
{
	if (sloc == SIZE) {
		PRINT(QUEUE filled with);
		return;
	}
	q[++sloc] = val;
	size++;
}

int queue::qget()
{
	if (rloc == sloc) {
		PRINT(QUEUE 0);
		return 0;
	}
	return q[++rloc];
	size--;
}


int main(int argc, char* argv[])
{

	string str;
	string arg;
	queue q;
	int i;
	int ii;
	cout << "enter command in format: [command] <arg> (type help for more information)" << endl;
	while (true)
	{

		getline(cin, str);
		if (!str.find("add")) {
			int i = str.find(" ");
			arg = str.substr(i + 1, str.length() - i);
			//cout << arg << endl;
			ii = atoi(arg.c_str());
			q.qput(ii);
		}
		
		else if (!str.find("get")) {
			cout << q.qget() << endl;
		}
		else if (!str.find("exit")) {
			break;
		}
		else if (!str.find("help")) {
			cout << "programm 'queue'\nadd <arg> - add an <arg> in the queue\nget - show and pop the argument\nhelp - show help \nexit - for exit" << endl;
		}

	}

	
	return 0;


	/*queue q1;
	int value;
	int i;
	const int COUNT = 3;

	q1.init();

	for (i = 0; i < COUNT; ++i)
	{
		cout << " Enter val = ";
		cin >> value;
		q1.qput(value);
	}

	cout << " QUEUE : ";

	for (i = 0; i < COUNT; ++i)
		cout << q1.qget() << "   ";

	cout << endl;


	system("pause");
	return 0;*/
}