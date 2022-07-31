#pragma once
#include <list>
#include "Animation.h"

class Session
{
public:
	Session();
	~Session();

	void Run();

private:
	unsigned int m_RuntimeMilliseconds = 0;
	IDisplay display;
};

class RollingSession
{
protected:
	virtual void AddAnimationCallback() = 0;
private:
	std::list<Animation> m_Animations;
	unsigned int m_Speed = 0;
};

class StockEnumerator
{
public:
	std::string GetNextStock();
private:
	std::vector<std::string> m_Tickers;
};

class StockSession : public RollingSession
{

protected:
	virtual void AddAnimationCallback() override;
private:
};


class NestedSession
{

};
