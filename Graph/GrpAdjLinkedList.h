#include <cstring>
#include <iostream>
#include "Stack.h"
#define elementType char
#define eInfoType int
#define MaxLen 100
#define INF 1000000000  // 一个很大的数，模拟无穷
enum GraphKind {UDG, UDN, DG, DN};


struct EdgeNode
{
	int adjVer;
	int eInfo;
	EdgeNode* next;
};

struct VerNode
{
	char data;
	EdgeNode* firstEdge;
	
};

struct Graph
{
	VerNode VerList[MaxLen];
	GraphKind gKind;
	int VerNum;
	int ArcNum;
};

void strLTrim(char* str);  //删除字符串左边空格

// 函数功能：统计图 G 中的边或弧的数量
// 参数：Graph &G —— 已构造的图（邻接表形式）
// 返回值：int —— 边（或弧）的数量
int countEdges(Graph &G) {
    int count = 0;

    // 遍历图中每个顶点
    for (int i = 1; i <= G.VerNum; ++i) {
        EdgeNode *p = G.VerList[i].firstEdge;

        // 遍历当前顶点的边链表，统计边数
        while (p) {
            count++;
            p = p->next;
        }
    }

    // 对于无向图，每条边在两个顶点中各存储了一次，需除以 2
    if (G.gKind == UDG || G.gKind == UDN)
        return count / 2;
    else  // 有向图中每条弧只存储一次
        return count;
}

#define elementType char

// 查找顶点 v 的编号（从 1 开始）
int getIndex(Graph *G, elementType v) {
    for (int i = 1; i <= G->VerNum; ++i) {
        if (G->VerList[i].data == v)
            return i;
    }
    return -1; // 未找到
}

// 函数功能：返回顶点 v 的第一个邻接点
// 参数：G —— 图；v ——顶点字符
int firstAdj(Graph *G, elementType v) {
    int index = getIndex(G, v);
    if (index == -1 || G->VerList[index].firstEdge == NULL)
        return -1; // 顶点不存在或无邻接点

    return G->VerList[index].firstEdge->adjVer; // 返回邻接点位置
}


// 函数功能：返回顶点 v 的邻接点 w 的下一个邻接点下标，若无返回 -1
// 参数：G —— 图；v ——顶点；w —— v 的一个邻接点
int nextAdj(Graph *G, elementType v, elementType w) {
    int indexV = getIndex(G, v);
    int indexW = getIndex(G, w);
    if (indexV == -1 || indexW == -1)
        return -1; // 顶点不存在

    EdgeNode *p = G->VerList[indexV].firstEdge;
    while (p && p->adjVer != indexW) {
        p = p->next;
    }
    if (p && p->next) {
        return p->next->adjVer;
    }
    return -1; // 没有下一个邻接点
}


void dfs(Graph *G, int v, int *visited, int *count) {
    visited[v] = 1;
    (*count)++;
    int w = firstAdj(G, v);
    while (w != -1) {
        if (!visited[w])
            dfs(G, w, visited, count);
        w = nextAdj(G, v, w);
    }
}


bool isDirectedTree(Graph *G, elementType v0) {
    int inDegree[MaxLen] = {0};
    int visited[MaxLen] = {0};
    int count = 0;

    int v0Index = getIndex(G, v0);
    if (v0Index == -1) return false;

    // 统计每个点的入度
    for (int i = 1; i <= G->VerNum; ++i) {
        int w = firstAdj(G, i);
        while (w != -1) {
            inDegree[w]++;
            w = nextAdj(G, i, w);
        }
    }

    // 确认仅有一个入度为 0 的顶点且它是 v0
    int rootCount = 0, rootIndex = -1;
    for (int i = 1; i <= G->VerNum; ++i) {
        if (inDegree[i] == 0) {
            rootCount++;
            rootIndex = i;
        }
    }
    if (rootCount != 1 || rootIndex != v0Index)
        return false;

    // 用 DFS 检查从 v0 是否能访问所有顶点
    dfs(G, v0Index, visited, &count);

    return count == G->VerNum;
}

void GenerateDFSTree(Graph *G, int B[MaxLen][MaxLen]) {
    int visited[MaxLen] = {0};  // 标记顶点是否访问过
    Stack<int> s(MaxLen);

    int v = 1;  // 假设从编号为1的顶点开始
    s.push(v);
    visited[v] = 1;

    while (!s.empty()) {
        int curr;
        s.getTop(curr);

        int w = firstAdj(G, curr);
        bool found = false;

        while (w != -1) {
            if (!visited[w]) {
                B[curr][w] = 1;
                B[w][curr] = 1;  // 若是无向图，存对称边
                s.push(w);
                visited[w] = 1;
                found = true;
                break;
            }
            w = nextAdj(G, curr, w);
        }

        if (!found) s.pop();  // 若没有未访问邻接点则回退
    }
}



//***************************2 文件创建图****************************//
//* 函数功能：从文本文件创建邻接表表示的图                        *//
//* 入口参数  char fileName[]，文件名                               *//
//* 出口参数：Graph &G，即创建的图                                  *//
//* 返 回 值：bool，true创建成功；false创建失败                     *//
//* 函 数 名：CreateGrpFromFile(char fileName[], Graph &G)          *//
//* 备    注：本函数使用的数据文件以邻接矩阵为输入数据              *//
//*******************************************************************//
int CreateGrpFromFile1(char fileName[], Graph &G)
{
	FILE* pFile;     //定义顺序表的文件指针
	char str[1000];  //存放读出一行文本的字符串
	char strTemp[10]; //判断是否注释行
	char* ss; 
    int i=0,j=0;
	int edgeNum=0;  //边的数量

	GraphKind graphType;  //图类型枚举变量

	pFile=fopen(fileName,"r");
	if(!pFile)
	{
		printf("错误：文件%s打开失败。\n",fileName);
		return false;
	}
	
	ss=fgets(str,1000,pFile);
	strncpy(strTemp,str,2);
	while((ss!=NULL) && (strstr(strTemp,"//")!=NULL) )  //跳过注释行
	{
		ss=fgets(str,1000,pFile);
		strncpy(strTemp,str,2);
		//cout<<strTemp<<endl;
	}
	    //循环结束，str中应该已经是文件标识，判断文件格式
	//cout<<str<<endl;
	if(strstr(str,"Graph")==NULL)
	{
		printf("错误：打开的文件格式错误！\n");
		fclose(pFile); //关闭文件
		return false;
	}
    //读取图的类型
	if(fgets(str,1000,pFile)==NULL)
	{
		printf("错误：读取图的类型标记失败！\n");
		fclose(pFile); //关闭文件
		return false;
	}
    //设置图的类型
	if(strstr(str,"UDG"))
		graphType=UDG;  //无向图
	else if(strstr(str,"UDN"))
		graphType=UDN;  //无向网
	else if(strstr(str,"DG"))
		graphType=DG;   //有向图
	else if(strstr(str,"DN"))
		graphType=DN;   //有向网
	else
	{
		printf("错误：读取图的类型标记失败！\n");
		fclose(pFile); //关闭文件
		return false;
	}

	//读取顶点元素，到str
	if(fgets(str,1000,pFile)==NULL)
	{
		printf("错误：读取图的顶点元素失败！\n");
		fclose(pFile); //关闭文件
		return false;
	}


	//顶点数据放入图的顶点数组		
	char* token=strtok(str," ");
	int nNum=1;	
	while(token!=NULL)
	{
		G.VerList[nNum].data=*token;
		G.VerList[nNum].firstEdge=NULL;
		//p=NULL;
		//eR=G.VerList[i].firstEdge;
        token = strtok( NULL, " ");
		nNum++;
	}
	
    //循环读取邻接矩阵数据
	int nRow=1;		//矩阵行下标
	int nCol=1;		//矩阵列下标
	EdgeNode* eR;	//边链表尾指针
	EdgeNode* p;    
	
	while(fgets(str,1000,pFile)!=NULL)
	{
		eR=NULL;
		p=NULL;
		nCol=1;  //列号设为0，一行重新开始
		char* token=strtok(str," ");  //以空格为分隔符，分割一行数据，写入邻接矩阵
		while(token!=NULL)
		{			
			if(atoi(token)>=1 && atoi(token)<INF)  //考虑到网
			{
				p=new EdgeNode;  //申请一个边链表结点
				p->adjVer=nCol;   //顶点的编号，从1开始
				p->eInfo=atoi(token);  //有权图保存权值，无权图为1
				p->next=NULL;
				if(G.VerList[nRow].firstEdge==NULL)
				{
					G.VerList[nRow].firstEdge=p;
					eR=p;
				}
				else
				{
					eR->next=p;
					eR=p;  //新的尾指针				
				}				
				edgeNum++;   //边数加1
			}
			token = strtok( NULL, " ");  //读取下一个子串
			nCol++;
		}
		nRow++; //一行数据处理完毕
	}

    G.VerNum=nNum;  //图的顶点数
	if(graphType==UDG || graphType==UDN)
		G.ArcNum=edgeNum / 2;  //无向图或网的边数等于统计的数字除2  
	else
		G.ArcNum=edgeNum;

	G.gKind=graphType;  //图的类型

	fclose(pFile); //关闭文件
	return true;
}

//***************************3 文件创建图****************************//
//* 函数功能：从文本文件创建邻接矩阵表示的图                        *//
//* 入口参数  char fileName[]，文件名                               *//
//* 出口参数：Graph &G，即创建的图                                  *//
//* 返 回 值：bool，true创建成功；false创建失败                     *//
//* 函 数 名：CreateGraphUDFromFile(char fileName[], Graph &G)      *//
//* 备注：本函数使用的数据文件格式以边（顶点对）为基本数据          *//
//*******************************************************************//
int CreateGraphFromFile(char fileName[], Graph &G)
{
	FILE* pFile;			//定义顺序表的文件指针
	char str[1000];			//存放读出一行文本的字符串
	char strTemp[10];		//判断是否注释行

    int i=0,j=0;
	int edgeNum=0;			//边的数量

	eInfoType eWeight;		//边的信息，常为边的权值
	GraphKind graphType;	//图类型枚举变量

	pFile=fopen(fileName,"r");
	if(!pFile)
	{
		printf("错误：文件%s打开失败。\n",fileName);
		return false;
	}
	
	while(fgets(str,1000,pFile)!=NULL)  //跳过空行和注释行
	{
			//删除字符串左边空格
		strLTrim(str);
		if (str[0]=='\n')  //空行，继续读取下一行
			continue;

		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)  //跳过注释行
			continue;
		else	 //非注释行、非空行，跳出循环
			break;
	}

		//循环结束，str中应该已经是文件标识，判断文件格式
	if(strstr(str,"Graph")==NULL)
	{
		printf("错误：打开的文件格式错误！\n");
		fclose(pFile); //关闭文件
		return false;
	}

		//读取图的类型，跳过空行及注释行
	while(fgets(str,1000,pFile)!=NULL)
	{
			//删除字符串左边空格
		strLTrim(str);
		if (str[0]=='\n')  //空行，继续读取下一行
			continue;

		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)  //注释行，跳过，继续读取下一行
			continue;		
		else  //非空行，也非注释行，即图的类型标识
			break;

	}

		//设置图的类型
	if(strstr(str,"UDG"))
		graphType=UDG;  //无向图
	else if(strstr(str,"UDN"))
		graphType=UDN;  //无向网
	else if(strstr(str,"DG"))
		graphType=DG;   //有向图
	else if(strstr(str,"DN"))
		graphType=DN;   //有向网
	else
	{
		printf("错误：读取图的类型标记失败！\n");
		fclose(pFile); //关闭文件
		return false;
	}


		//读取顶点元素，到str。跳过空行
	while(fgets(str,1000,pFile)!=NULL)
	{
		//删除字符串左边空格
		strLTrim(str);
		if (str[0]=='\n')  //空行，继续读取下一行
			continue;

		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)  //注释行，跳过，继续读取下一行
			continue;		
		else  //非空行，也非注释行，即图的顶点元素行
			break;
	}

	//顶点数据放入图的顶点数组		
	char* token=strtok(str," ");
	int nNum=0;	
	while(token!=NULL)
	{
		G.VerList[nNum+1].data=*token;
		G.VerList[nNum+1].firstEdge=NULL;
		//p=NULL;
		//eR=G.VerList[i].firstEdge;
        token = strtok( NULL, " ");
		nNum++;
	}
	
    //循环读取边（顶点对）数据
	int nRow=1;  //矩阵行下标
	int nCol=1;  //矩阵列下标
	EdgeNode* eR;  //边链表尾指针
	EdgeNode* p;    

	elementType Nf,Ns; //边或弧的2个相邻顶点
	while(fgets(str,1000,pFile)!=NULL)
	{
		//删除字符串左边空格
		strLTrim(str);
		if (str[0]=='\n')  //空行，继续读取下一行
			continue;
		
		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)  //注释行，跳过，继续读取下一行
			continue;

		//nCol=0;  //列号设为0，一行重新开始
		char* token=strtok(str," ");  //以空格为分隔符，分割一行数据，写入邻接矩阵
		
		if(token==NULL)  //分割为空串，失败退出
		{
			printf("错误：读取图的边数据失败！\n");
			fclose(pFile); //关闭文件
			return false;
		}
		Nf=*token;  //获取边的第一个顶点
		
		token = strtok( NULL, " ");  //读取下一个子串，即第二个顶点
		if(token==NULL)  //分割为空串，失败退出
		{
			printf("错误：读取图的边数据失败！\n");
			fclose(pFile); //关闭文件
			return false;
		}

		Ns=*token;  //获取边的第二个顶点
            //从第一个顶点获取行号		
		for(nRow=1;nRow<=nNum;nRow++)
		{
			if(G.VerList[nRow].data==Nf)  //从顶点列表找到第一个顶点的编号
				break;
		}
           //从第二个顶点获取列号		
		for(nCol=1;nCol<=nNum;nCol++)
		{
			if(G.VerList[nCol].data==Ns)  //从顶点列表找到第二个顶点的编号
				break;
		}

		//如果为网，读取权值
		if(graphType==UDN || graphType==DN)
		{
			token = strtok( NULL, " ");  //读取下一个子串，即边的附加信息，常为边的权重
			if(token==NULL)  //分割为空串，失败退出
			{
				printf("错误：读取图的边数据失败！\n");
				fclose(pFile); //关闭文件
				return false;
			}
			eWeight=atoi(token);  //取得边的附加信息
		}


		eR=G.VerList[nRow].firstEdge;
		while(eR!=NULL && eR->next!=NULL)
		{
			eR=eR->next;  //后移边链表指针，直至尾节点
		}
		
		p=new EdgeNode;  //申请一个边链表结点
		p->adjVer=nCol;   //顶点的编号，从1开始
		if(graphType==UDN || graphType==DN) //边的附加信息，对有权图保存权值，无权图为1
			p->eInfo=eWeight;
		else
			p->eInfo=1; 
		p->next=NULL;
		
		if(G.VerList[nRow].firstEdge==NULL)
		{
			G.VerList[nRow].firstEdge=p;
			eR=p;
		}
		else
		{
			eR->next=p;
			eR=p;  //新的尾指针				
		}				

		edgeNum++;   //边数加1
	}
	


    G.VerNum=nNum;  //图的顶点数
	if(graphType==UDG || graphType==UDN)
		G.ArcNum=edgeNum / 2;  //无向图或网的边数等于统计的数字除2  
	else
		G.ArcNum=edgeNum;

	G.gKind=graphType;  //图的类型

	fclose(pFile); //关闭文件
	return true;
}

//删除字符串、字符数组左边空格
void strLTrim(char* str)
{
	int i,j;
	int n=0;
	n=strlen(str)+1;
	for(i=0;i<n;i++)
	{
		if(str[i]!=' ')  //找到左起第一个非空格位置
			break;
	}
	    //以第一个非空格字符为手字符移动字符串
	for(j=0;j<n;j++)
	{
		str[j]=str[i];
		i++;
	}
}

//销毁图
void DestroyGraph(Graph &G)
{
	EdgeNode *p,*u;
	int vID;
	for(vID=1; vID<=G.VerNum; vID++)  //循环删除每个顶点的边链表
	{
		p=G.VerList[vID].firstEdge;
		G.VerList[vID].firstEdge=NULL;
		while(p)  //循环删除当前顶点所有的关联边 
		{
			u=p->next;  //u指向下一个边结点
			delete(p);  //删除当前边结点
			p=u;
		}		
	}
	p=NULL;
	u=NULL;
	G.VerNum=-1;  //编辑图已经销毁
}