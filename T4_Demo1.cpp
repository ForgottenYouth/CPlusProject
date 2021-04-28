//使用C++的纯虚函数实现java的登录回调接口
#include <iostream>

using namespace std;

class Result {
public:
    string userName;
    string password;

    Result(string username, string pwd) : userName(username), password(pwd) {

    }

    //运算符重载
    friend ostream &operator<<(ostream &_START, Result &bean) {
        _START << "name=" << bean.userName << ",password=" << bean.password << endl;
        return _START;
    }

};

//全部纯虚函数，相当于java接口
class ILoginResponse {
public:
    virtual void loginSuccess(int code, string message, Result result) = 0;

    virtual void loginFailure(int code, string message) = 0;
};

class ILoginResponseImpl : public ILoginResponse {
public:
    void loginSuccess(int code, string message, Result result) override {
        cout << "ILoginResponseImpl-----loginSuccess" << endl;
        cout << "code=" << code << ",message=" << message << "result:=" << result << endl;
    }

    void loginFailure(int code, string message) override {
        cout << "ILoginResponseImpl-----loginFailure" << endl;
        cout << "code=" << code << ",message=" << message  << endl;
    }
};


void loginAction(string name, string password, ILoginResponse &response) {
    if ("hello" == name && "123456" == password) {
        Result bean(name, password);
        response.loginSuccess(200, "登录成功", bean);
    } else {
        response.loginFailure(12, "登录失败，账号或密码错误");
    }
}


int main() {
    string name;
    cout << "请输入用户名：";
    cin >> name;

    string password;
    cout << "请输入密码:";
    cin >> password;

    ILoginResponse *iLoginResponse = new ILoginResponseImpl();
    loginAction(name, password, *iLoginResponse);

    if (iLoginResponse) {
        delete iLoginResponse;
        iLoginResponse = NULL;
    }

    return 0;
}
