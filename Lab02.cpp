#include<bits/stdc++.h>
using namespace std;

struct LinkedList {
    string studentCode; // Ma so sinh vien
	string studentName; // Ten sinh vien
	float pointAverage; // Diem trung binh
	string type; // Xep loai
    struct LinkedList *next;
};
 
typedef struct LinkedList *node;
 
node CreateNode(string studentCode, string studentName, float pointAverage) {
    node temp;
    temp = (node)malloc(sizeof(struct LinkedList));
    temp->next = NULL;
    temp->studentCode = studentCode;
    temp->studentName = studentName;
    
    string type;
    if (pointAverage >= 9.0)
    	type = "Xuat sac";
    else if (pointAverage >= 8.0)
    	type = "Gioi";
    else if (pointAverage >= 6.5)
    	type = "Kha";
    else if (pointAverage >= 5.0)
    	type = "Trung Binh";
    else if (pointAverage >= 4.0)
    	type = "Yeu";
    else
    	type = "Kem";
    	
    temp->type = type;
    temp->pointAverage = pointAverage;
    return temp;
}

 
node AddTail(node head, string studentCode, string studentName, float pointAverage) {
    node temp, p;
    temp = CreateNode(studentCode, studentName, pointAverage);
    if(head == NULL){
        head = temp;
    } else {
        p  = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
    
    return head;
}


void PrintList(node head) {
    cout << endl;
    for(node p = head; p != NULL; p = p->next) {
        cout << "| " << p->studentCode << " | " << p->studentName << " | " << p->pointAverage << " | " << p->type << " |";
    }
}
 
node InitHead(){
    node head;
    head = NULL;
    return head;
}
 
int Length(node head){
    int length = 0;
    for(node p = head; p != NULL; p = p->next){
        ++length;
    }
    return length;
}
 
node Input() {
    node head = InitHead();
    int n;
    
    string studentCode; // Ma so sinh vien
	string studentName; // Ten sinh vien
	float pointAverage; // Diem trung binh
    
    do {
        cout << "Nhap so luong sinh vien: ";
        cin >> n;
    } while(n <= 0);
 
    for(int i = 0; i < n; i++) {
    	cout << "Nhap MSSV: ";
    	cin >> studentCode;
    	
    	cout << "Nhap ho ten sinh vien: ";
    	cin >> studentName;
    	
    	cout << "Nhap diem trung binh: ";
    	cin >> pointAverage;
    	
        head = AddTail(head, studentCode, studentName, pointAverage);
    }
    return head;
}


int main()
{
	node head = Input();
    PrintList(head);
	return 0;
}
