// AbstracteFactory.h: interface for the AbstracteFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ABSTRACTEFACTORY_H__0EC6F236_8383_4D5E_87CC_D95700B6D9D8__INCLUDED_)
#define AFX_ABSTRACTEFACTORY_H__0EC6F236_8383_4D5E_87CC_D95700B6D9D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <iostream>

class AbstractThreadLayer
{
public:
    virtual void create()=0;
    virtual void join()=0;

protected:
    AbstractThreadLayer() {};
    virtual ~AbstractThreadLayer() {};
};

class ThreadLayerWindows : public AbstractThreadLayer
{
public:
    void create() { std::cout<<"Windows Thread Created"<<std::endl;} ;
    void join()	{ std::cout<<"Windows Thread Joined"<<std::endl;} ;

    ThreadLayerWindows(){ std::cout<<"Windows Thread Layer"<<std::endl;} ;
    virtual ~ThreadLayerWindows() {} ;
};

class ThreadLayerLinux : public AbstractThreadLayer
{
public:
    void create() { std::cout<<"Linux Thread Created"<<std::endl;} ;
    void join()	{ std::cout<<"Linux Thread Joined"<<std::endl;} ;

    ThreadLayerLinux(){ std::cout<<"Linux Thread Layer"<<std::endl;} ;
    virtual ~ThreadLayerLinux(){}
};

class AbstractFileLayer
{
public:
    virtual void open()=0;
    virtual void close()=0;

protected:
    AbstractFileLayer() {};
    virtual ~AbstractFileLayer() {};
};

class FileLayerWindows : public AbstractFileLayer
{
public:
    void open() { std::cout<<"Windows File open"<<std::endl;} ;
    void close()	{ std::cout<<"Windows File close"<<std::endl;} ;

    FileLayerWindows() { std::cout<<"Windows File Layer"<<std::endl;} ;
    virtual ~FileLayerWindows() {};
};

class FileLayerLinux : public AbstractFileLayer
{
public:
    void open() { std::cout<<"Linux File open"<<std::endl;} ;
    void close()	{ std::cout<<"Linux File close"<<std::endl;} ;

    FileLayerLinux(){ std::cout<<"Linux File Layer"<<std::endl;} ;
    virtual ~FileLayerLinux() {};
};


class AbstractFactory
{
public:
    enum WorkingOperatingSystem {
        WINDOWS = 0,
        LINUX	= 1
    };
    virtual AbstractThreadLayer* createThreadLayer() = 0;
    virtual AbstractFileLayer* createFileLayer() = 0;
    AbstractFactory() {};
    virtual ~AbstractFactory() {};
};

class WindowsFactory  : public AbstractFactory
{
public:
    AbstractThreadLayer* createThreadLayer() {return new ThreadLayerWindows();};
    AbstractFileLayer* createFileLayer()  {return new FileLayerWindows();};
    WindowsFactory(){std::cout<<"Windows Factory Called"<<std::endl;};
    virtual ~WindowsFactory() {};
};

class LinuxFactory  : public AbstractFactory
{
public:
    AbstractThreadLayer* createThreadLayer() {return new ThreadLayerLinux();};
    AbstractFileLayer* createFileLayer()  {return new FileLayerLinux();};
    LinuxFactory() {std::cout<<"Linux Factory Called"<<std::endl;};
    virtual ~LinuxFactory() {};
};

extern void ClientAbstractFactory(int wos);

#endif // !defined(AFX_ABSTRACTEFACTORY_H__0EC6F236_8383_4D5E_87CC_D95700B6D9D8__INCLUDED_)
