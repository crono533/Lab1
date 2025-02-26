#include <iostream>
#include <string>
#include <memory>

class ILog
{
public:
    virtual void Logging(const std::string& log) = 0;
};

class DataBaseLogger : public ILog
{
public:
    void Logging(const std::string& log) override 
    {
        std::cout << "logging in database: "<< log << std::endl;
    }
};

class TxtLogger : public ILog 
{
public:
    void Logging(const std::string& log) override
    {
        std::cout << "logging in txt: "<< log << std::endl;
    }
};

class SmtpMailer
{
private:
    std::shared_ptr<ILog> logger;

public:

    SmtpMailer(std::shared_ptr<ILog> logger_) : logger(logger_) {}
    

    void SendMessage(const std::string& message)
    {
        logger->Logging(message);
    }
};




int main()
{
    std::shared_ptr<ILog> loggerTxt(new TxtLogger);
    SmtpMailer mailer(loggerTxt);
    std::string message = "hello!";
    mailer.SendMessage(message);


    std::shared_ptr<ILog> loggerDateBase(new DataBaseLogger);
    SmtpMailer mailer1(loggerDateBase);
    mailer1.SendMessage("hello!");


    return 0;
}

