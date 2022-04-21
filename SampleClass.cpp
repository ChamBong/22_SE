#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) { radius = r; }
	void setRadius(int r) { radius = r; }
	int getRadius() { return radius; }
	double getArea() { return 3.14 * radius * radius; }
};

class Sample {
	Circle* p; int capacity; int size;
public: // ������
	Sample(int n) { capacity = n; p = new Circle[n]; } // n�� �� ��ü�� �迭�� �������� ����
	void read(); // ���� �Ҵ���� �� ��ü�� �迭 p�� ����ڰ� ������ �Է�
	void write(); // ���� �� ��ü �迭�� �������� ȭ�鿡 ���
	Circle big(); // �� ��ü���� ���� ū �� ��ü�� ����
	int getSize() { return size; }
	~Sample() { delete[] p; } //�Ҹ���
};

// read ��� �Լ� ����
void Sample::read() {
	int inputSize, radius;
	cout << "�Է��ҷ��� ���� ������ ? ";
	cin >> inputSize;
	size = inputSize;
	cout << size << "���� ���� �������� �Է��Ͻÿ�. ";
	for (int i = 0; i < size; i++) {
		cin >> radius;
		p[i].setRadius(radius);
	}
}

// write ��� �Լ� ����
void Sample::write() {
	for (int i = 0; i < size; i++)
		cout << p[i].getRadius() << ' '; // �Է��� ������ ���
	cout << endl << endl;
}

// big ��� �Լ� ����
Circle Sample::big() {
	int b = p[0].getRadius();
		for (int i = 1; i < size; i++)
			if (b < p[i].getRadius())
				b = p[i].getRadius();
		return b; // �ִ밪 ��ȯ
}

int main() {
	Sample s(10); // 10�� ���� �� ��ü �迭�� ���� Sample ��ü ����
	s.read(); // Ű����� �� �� ��ü�� �������� ����
	cout << "�� �� ��ü�� ������ " << s.getSize() << "���� ����մϴ�. ";
	s.write(); // �� ���� ����ü�� ������ ���
	Circle big = s.big(); // ���� ū ����ü ����
	cout << "���� ū ���� ���� : " << big.getArea() << "\t ���� ū ���� ������ : " << big.getRadius() << endl; // ���� ū �� ���
}