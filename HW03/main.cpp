//main.cpp

#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Inventory {
private:
	T* pItems_;
	int capacity_;
	int size_ = 0;
public:
	Inventory(int capacity = 10) : capacity_(capacity) {
		if (capacity == 0) {
			capacity_ = 1;
		}
		pItems_ = new T[capacity_];
	}

	~Inventory() {
		delete[] pItems_;
		pItems_ = nullptr;
	}

	void AddItem(const T& item) {
		if (size_ != capacity_) {
			pItems_[size_] = item;
			++ size_;
			cout << "인벤토리에 " << item << "을/를 추가했습니다." << endl;
		}
		else {
			cout << "인벤토리가 꽉 찼습니다!" << endl;
		}
	}

	void RemoveLastItem() {
		if (size_ == 0) {
			cout << "인벤토리가 비어있습니다." << endl;
		}
		else {
			string item = pItems_[size_ -1];
			cout << item <<"을/를 인벤토리에서 버렸습니다." << endl;
			-- size_;
		}
	}

	void PrintAllItems() const {
		cout << "[인벤토리]" << endl;
		if (size_ == 0) {
			cout << "인벤토리가 비어 있습니다." << endl;
		}
		else {
			for (int i = 0; i < size_; i++) {
				cout << i+1 << ". " << pItems_[i] << endl;
			}
		}
	}

	int GetSize() const {
		return size_;
	}

	int GetCapacity() const {
		return capacity_;
	}

};


int main()
{
	Inventory<string>* itemInventory = new Inventory<string>();

	itemInventory->AddItem("화살");
	itemInventory->AddItem("칼");
	itemInventory->AddItem("지팡이");
	itemInventory->AddItem("활");
	itemInventory->AddItem("단검");
	itemInventory->AddItem("나무");
	itemInventory->AddItem("자갈");
	itemInventory->AddItem("모래");
	itemInventory->AddItem("부러진 검");
	itemInventory->AddItem("쓰레기");
	itemInventory->AddItem("돌");

	itemInventory->PrintAllItems();

	itemInventory->RemoveLastItem();

	itemInventory->PrintAllItems();

	delete itemInventory;


	return 0;
}
