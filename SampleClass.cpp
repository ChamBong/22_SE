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
public: // 생성자
	Sample(int n) { capacity = n; p = new Circle[n]; } // n개 원 객체를 배열로 동적으로 생성
	void read(); // 동적 할당받은 원 객체의 배열 p에 사용자가 반지름 입력
	void write(); // 동적 원 객체 배열의 반지름을 화면에 출력
	Circle big(); // 원 객체에서 가장 큰 원 객체를 리턴
	int getSize() { return size; }
	~Sample() { delete[] p; } //소멸자
};

// read 멤버 함수 구현
void Sample::read() {
	int inputSize, radius;
	cout << "입력할려는 원의 갯수는 ? ";
	cin >> inputSize;
	size = inputSize;
	cout << size << "개의 원의 반지름을 입력하시오. ";
	for (int i = 0; i < size; i++) {
		cin >> radius;
		p[i].setRadius(radius);
	}
}

// write 멤버 함수 구현
void Sample::write() {
	for (int i = 0; i < size; i++)
		cout << p[i].getRadius() << ' '; // 입력한 반지름 출력
	cout << endl << endl;
}

// big 멤버 함수 구현
Circle Sample::big() {
	int b = p[0].getRadius();
		for (int i = 1; i < size; i++)
			if (b < p[i].getRadius())
				b = p[i].getRadius();
		return b; // 최대값 반환
}

int main() {
	Sample s(10); // 10개 동적 원 객체 배열을 가진 Sample 객체 생성
	s.read(); // 키보드로 각 원 객체에 반지름을 저장
	cout << "각 원 객체의 반지름 " << s.getSize() << "개를 출력합니다. ";
	s.write(); // 각 동적 원객체의 반지름 출력
	Circle big = s.big(); // 가장 큰 원객체 리턴
	cout << "가장 큰 원의 넓이 : " << big.getArea() << "\t 가장 큰 원의 반지름 : " << big.getRadius() << endl; // 가장 큰 원 출력
}