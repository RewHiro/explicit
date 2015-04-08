//
//�@explicit�ƕϊ��R���X�g���N�^
//


#include <string>
#include <iostream>

class Test{
	int a = 0;
	int c = 0;
public:

	~Test(){
		std::cout << "�f�X�g���N�^" << std::endl;
	}

	///*explicit*/ Test(int a):
	//	a(a)
	//{}

	//�@���̏ꍇ���ϊ��R���X�g���N�^���Ȃ����
	/*explicit*/ Test(int a,int c = 0) :
		a(a),
		c(c)
	{
		std::cout << "�R���X�g���N�^" << std::endl;
	}

	void Show()const{
		std::cout << a << std::endl;
	}


};

void Func01(const Test& test){
	test.Show();
}

void Func02(Test test){
	test.Show();
}
void Func03(Test& test){
	test.Show();
}


int main(){
	//�@�ϊ��R���X�g���N�^
	Test b = 0;
	b.Show();

	//�@�R�s�[�R���X�g���N�^���s���Ă���
	b = 60;
	b.Show();

	//�@Test�N���X���Q�Ƃ����������̂ɐ����^��10�������Ă��܂��Ă���
	//�@10 -> Test(10)���ÖٓI�ɍs���Ă�
	Func01(10);
	Func02(40);

	//�@�킩��ɂ����̂�explicit������
	//�@�܂��A�o�O���N����₷���炵���̂�explicit������̂�����
	//�@�܂�R���X�g���N�^�̈����ɍ\���́A�N���X�ȊO�̗\���(int,float,double,char,string��)������Ȃ���������悢

	//�@����������������������������������������������������������������������������������������������
	//�@MEMO
	//�@����������������������������������������������������������������������������������������������
	
	//Func03(30);
	//�@��L��Func03���G���[�ɂȂ�͈̂ꎞ�I�ɃI�u�W�F�N�g������
	//�@�ł�Func03(Test(30))���ꎞ�I�u�W�F�N�g�Ȃ̂ɃR���p�C�����ʂ�̂��킩��Ȃ�
}