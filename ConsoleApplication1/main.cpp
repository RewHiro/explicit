//
//　explicitと変換コンストラクタ
//


#include <string>
#include <iostream>

class Test{
	int a = 0;
	int c = 0;
public:

	~Test(){
		std::cout << "デストラクタ" << std::endl;
	}

	///*explicit*/ Test(int a):
	//	a(a)
	//{}

	//　この場合も変換コンストラクタがなされる
	/*explicit*/ Test(int a,int c = 0) :
		a(a),
		c(c)
	{
		std::cout << "コンストラクタ" << std::endl;
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
	//　変換コンストラクタ
	Test b = 0;
	b.Show();

	//　コピーコンストラクタを行っている
	b = 60;
	b.Show();

	//　Testクラスを参照したかったのに整数型の10が入ってしまっている
	//　10 -> Test(10)を暗黙的に行ってる
	Func01(10);
	Func02(40);

	//　わかりにくいのでexplicitをつける
	//　また、バグが起こりやすいらしいのでexplicitをつけるのが無難
	//　つまりコンストラクタの引数に構造体、クラス以外の予約語(int,float,double,char,string等)があるならつけた方がよい

	//　＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
	//　MEMO
	//　＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
	
	//Func03(30);
	//　上記のFunc03がエラーになるのは一時的にオブジェクトだから
	//　でもFunc03(Test(30))も一時オブジェクトなのにコンパイルが通るのがわからない
}