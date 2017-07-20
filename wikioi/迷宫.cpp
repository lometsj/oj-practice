///////////////////////////////////////////////////
//C++��Ҫ�����ͺ�������
//////////////////maze.h///////////////////////////
//ȫ�ֱ���
#ifndef _GLOBAL_VAR_
#define _GLOBAL_VAR_

#include "MazeClass.h"

class CMaze   *game = NULL;   //�Թ������ָ��
class CRoom   **map;          //��Ϸmapָ��

HWND       hWndMain;          //�����ھ��
HBITMAP    h_MemBm = NULL;    //�ڴ�λͼ
HDC        h_MemDC = NULL;    //�ڴ�DC
RECT       rCliRet;           //��Ϸ���ڴ�С
HBRUSH     hBrushes[10];      //���Ʒ���Ļ�ˢ

#endif

//////////////////LinkList.h///////////////////////

#ifndef _LINK_LIST_H
#define _LINK_LIST_H

#include <iostream.h>

template <class T>
class Node
{
private:
    Node<T> *nextptr;
public:
    T data;
    Node();
    ~Node();
    Node <T> *next() const;
    Node(const T &item, Node<T> *ptrnext=NULL);
    void setNext(Node<T> *ptrnext=NULL);
};

template <class T>
class LinkList
{
private:
    Node<T> *head;
    Node<T> *tail;
    Node<T> *curr;
    Node<T> *getNode(const T &item, Node<T> *ptrnext=NULL);
    void freeNode(Node <T> *p);
    int size;
public:
    LinkList();
    ~LinkList();
    Node<T> *next();
    Node<T> *current();
    Node<T> *first();
    Node<T> *last();
    Node<T> *findNode(int index);
    Node<T> *findNode(const T &item); //�˹�����Ҫģ�������ص��������
    void reset();
    int getSize();
    int insertFront(const T &item);
    int insertTail(const T &item);
    int insertAfter(const T &item, int index);
    int deleteFront(T *item);
    int deleteTail(T *item);
    int deleteNode(T *item, int index);
    void clear();
    bool isEmpty();
};


#endif

//////////////MazeClass.h///////////////////////////

#ifndef _MAZE_CLASS_H
#define _MAZE_CLASS_H

#include <iostream.h>
#include <string.h>
#include <time.h>
#include "LinkList.h"

//�����ⲿ����
extern HWND       hWndMain;        // �����ھ��
extern HBITMAP    h_MemBm;         // �ڴ�λͼ
extern HDC        h_MemDC;         // �ڴ�DC
extern RECT       rCliRet;         // ���ڴ�С
extern class  CMaze *game;         // �Թ���ָ��
extern class  CRoom  **map;        //��Ϸmapָ��
extern HBRUSH    hBrushes[10];     //����·����ˢ

#define RIGHT            0         //����
#define DOWN             1         //����
#define LEFT             2         //����
#define UP               3         //���
#define NODIR            4

#define LEFT_WALL        0         //���ǽ��
#define UP_WALL          1         //����ǽ��
#define IS_WALL          0         //��ǽ��
#define NO_WALL          1         //û��ǽ��
#define HAS_DEAL         0         //map����״̬���Ѿ�����
#define IN_DEAL          1         //���ڴ���
#define NOT_DEAL         2         //δ����
#define STEP             12        //��������

#define AUTO_MODE        0         //������͵����Զ�
#define PLAY_MODE        1         //�ֶ�
#define INIT             0         //���״̬��ʼ��
#define GOING            1         //����
#define STOP             2         //��ͣ
#define OVER             3         //����

#define IDT_TIMER1       1         // ��ʱ�����
#define IDT_TIMER2       2

//�������
class point
{
public:
    int x;
    int y;
    point();
    ~point();
    point(int x, int y);
    point(const point &p);
    point &operator =(const point &p);
    bool operator ==(const point &p);
};

//Room��,�����Թ��õ�
class CRoom
{
    friend class CMaze;
private:
    point  pos;
    int    status;            //0:δ����,  1:���ڷ���, 2:�ѷ���
    int    upstatus;          //0:����ͨ�� 1:������ͨ��
    int    leftstatus;        //0:����ͨ�� 1:������ͨ��
                              //ÿ���ڵ�ֻ���ж�up&left�Ƿ����ͨ������
};

//�Թ�ǽ����
class CWall
{
    friend class CMaze;
private:
    point pos;      //ǽ��λ��
    int dir;        //���� 1:�� 0:��
public:
    CWall();
    CWall(const point &pos, const int &dir);
    CWall(const CWall &p);
    ~CWall();
    CWall &operator =(const CWall &p);
    bool operator ==(const CWall &p);
};

class CBoard
{
protected:
    HBRUSH    hBrush;      //���Ʊ�����ˢ
    HPEN      hPen;        //���Ʊ߿��ߵĻ���
    point   m_pos, m_entry, m_exit;
    int     m_size, m_cell, m_nx, m_ny;
    int     m_mode, m_speed, m_status;
    void fillCell(point pos, int color, int dir);
    void displayText(point p, char *text);
public:
    CBoard();
    ~CBoard();
    int   getCell();
    int   getMode();
    int   getSpeed();
    int   getStatus();
    int   getSize();
    point getPos();
    point getEntry();
    point getExit();
    void  messageBox(char *errMsg, char *title, int style);
    void  setTimer(int id, int time);
    void  killTimer(int id);
};

//·���ڵ���
class CPathNode
{
    friend class CPlayer;
private:
    int   index;              //�ڵ��������б��
    int   indir;              //�����ȥ����
    int   outdir;             //���һ�γ�ȥ����
    class point pos;          //�ڵ�λ��
public:
    CPathNode();
    CPathNode(point pos, int index, int indir, int outdir);
    ~CPathNode();
    CPathNode(const CPathNode &p);
    CPathNode &operator =(const CPathNode &p);  //���ظ�ֵ�����
    bool operator ==(const CPathNode &p);       //���ص��ں�
};

//��Ϸ�����
class CPlayer: public CBoard
{
private:
    int  curdir;           //��ǰ���ƶ�����
    int  steps;            //��ǰ����
    time_t usedTime, stopTime;       //����ʱ����ʱ
    LinkList <class CPathNode> path;    //�����߹�����ȷ·������
    LinkList <class CPathNode> error;   //�����߹��Ĵ���·������
    LinkList <class CWall> *mazeptr;    //ָ��ǰ�Թ���ָ��
    int  canMove();
    int  doOper();
    int  autoGo();
    void errOut(char *errMsg);
    void showInfo();
    void drawPath();
public:
    CPlayer(CMaze *maze);
    ~CPlayer();
    void onKeyDown(unsigned short key);
    void onTimer(int id);
};

class CMaze: public CBoard
{
private:
    LinkList <class CWall> wlist;   //����Թ�ǽ����������
    class CPlayer *m_player;
    void drawWall(class CWall wall);
    int  createWallList(LinkList<class point> *list);
    int  chgRoomStatus(point pos, LinkList<class point> *list, int dir, int depth);
    int  createMaze();
    void drawMaze();
    void showTime();
    void showHelpInfo();
    void initBkGnd();
    int  newGame();
    void gameOver();
public:
    CMaze();
    ~CMaze();
    void dialogBox(HINSTANCE hInst, LPCTSTR IDD, DLGPROC myFunc);
    int  onInit();
    void initDlg(HWND hDlg);
    void onDlgOk(HWND hDlg);
    void onTimer(int id);                //��Ϸ���غ���
    void onKeyDown(unsigned short key);  //��Ϸ���غ���
    void onPaint(HDC hdc);
    LinkList<class CWall> *getWallList();
};

#endif

////////////////////////////////////////////
//C������Ҫ�����ͺ�������
////////////////maze.h//////////////////////
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define M                 50000         /* �Թ����ǽ���� */
#define MAX_NODE_NUMBER   50000         /* �������ڴ�ڵ� */
#define MAXGRADE          150           /* ��Ϸ����Ѷ� */
#define IDT_TIMER1        1             /* ��ʱ����� */
#define IDT_TIMER2        2
#define STEP              16            /* �������� */

#define RIGHT             0
#define DOWN              1
#define LEFT              2
#define UP                3

#define AUTO_MODE         0
#define PLAY_MODE         1

#define UP_WALL           0
#define LEFT_WALL         1

#define INIT              0
#define GOING             1
#define STOP              3
#define OVER              4

struct position
{
    int x;
    int y;
};

struct GameInfo
{
    struct position pos;      /* ����λ������ */
    int    size;              /* ��С */
    int    timer;
    int    nx;
    int    ny;
    int    cell;
    int    mode;
    int    mazemode;
    int    speed;
    int    times;
    int    status;
}game;

struct MazeWall
{
    struct position pos;
    int diretcion;       /* ���� 0:�� 1:�� */
};

struct MazeCfg
{
    struct MazeWall data[M];       /* ǽ����������   */
    struct position entry, exit;   /* ��ںͳ���λ�� */
    int    num;                    /* ǽ�ڸ���       */
}maze;

struct MapCfg
{
    struct position pos;
    int    status;            /* 0:δ����, 1:���ڷ���, 2:�ѷ��� */
    int    upstatus;          /* 0:����ͨ�� 1:������ͨ�� */
    int    leftstatus;        /* 0:����ͨ�� 1:������ͨ�� */
                              /* ÿ���ڵ�ֻ���ж�up&left�Ƿ����ͨ������ */
};

struct MapCfg  **map;

struct travInfo
{
    struct position pos;
    struct travInfo *next;
};

struct RoadInfo
{
    int    index;             /* ��� */
    int    indir;             /* ��ȥ���� */
    int    outdir;            /* ��ȥ���� */
    struct position pos;
    struct RoadInfo *next;
};

struct playercfg
{
    int    direction;
    int    steps;
    time_t usedTime, endTime, stopTime;
    struct RoadInfo *RoadPtr, *errPtr;
}play;

HWND       hWndMain;         /* �����ھ�� */
HBITMAP    h_MemBm = NULL;   /* �ڴ�λͼ */
HDC        h_MemDC = NULL;   /* �ڴ�DC */


HBRUSH  hBrushes[10];     /* ���Ʒ���Ļ�ˢ */
HBRUSH  hBrushBkGnd;     /* ����ɫ��ˢ */
HPEN    hPenBorder;      /* ���Ʊ߿��ߵĻ��� */

int initgame(HWND hWnd);
int markpath(int x, int y, int dir, int color);
int drawWall(int x, int y, int dir);
int drawMaze();
int readMazedata(int *num, int id);
char *GetFldStr(char *sFldStr, char *sStr, char sFld);
void initMalloc();
void addMallocNode(char *);
void freeMallocNode();
void *gcCalloc(size_t , size_t);
int  initBkGnd();
int createMaze();
int getWallCfg();
int setDirStatus(struct position pos, struct travInfo *head, int dir, int depth);
int createPlayer(int mode);
int destroyPlayer();
int canMove();
int doOperation();
int havePathed(struct RoadInfo node);
int newGame(int type, int mode);
void drawPath();
void showTime();
int gameOver();
int autoGo(int num);
void DisplayText(int posx, int posy, char *text);
int initGameSet(HWND hDlg);
int chgGameStatus();
void showUsedTime();
void showPlayInfo();
void errOut(char *errMsg);
