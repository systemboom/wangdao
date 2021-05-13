//
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"tinyxml2.h"

using namespace tinyxml2;
using std::vector;
using std::cout;
using std::endl;
using std::string;
class information{
    public:
        ~information(){
            cout<<"~information"<<endl;
        }
    public:
        string title;
        string link;
        string description;
        string  content;
        string lagnguage;
        string copyright;
        string pubdate; 
        string guid;
        string dccreator;
};
void traverse(vector <information> * _vecotr){
//  string filename = "pagelib.dat";
    std::ofstream _ostream("pagelib.dat",std::ios::app);

    vector<information>::iterator _begin= _vecotr->begin();
    vector<information>::iterator _end= _vecotr->end();

    ++_begin;
    while(_begin!=_end){
        _ostream<<"<doc>"<<endl;
        _ostream<<"<title>"<<_begin->title<<"</title>"<<endl;
        _ostream<<"<link>"<<_begin->link<<"</link>"<<endl;
        _ostream<<"<description>"<<_begin->description<<"</description>"<<endl;
//      _ostream<<"<content>"<<_begin->content<<"</content>"<<endl;
        _ostream<<"</doc>"<<endl;
        ++_begin;
    }
}
void example1(){
    vector<information> information_vector;
    XMLDocument doc;
    doc.LoadFile("coolshell.xml");

    cout<<doc.Error()<<endl;
    if(0!=doc.Error()){
        cout<<"load file error"<<endl;
        return;
    }
//  doc.Print();
    XMLElement*  root = doc.RootElement();
    XMLElement* channel = root->FirstChildElement("channel");
    if(NULL==channel){
        cout<<"get first chile element error "<<endl;
        return ;
    }
    XMLElement * title = channel->FirstChildElement("title");
    cout<<title->GetText()<<endl;
    cout<<title->Name()<<endl;

    XMLElement * description = title->NextSiblingElement();
    cout<<description->GetText()<<endl;
    cout<<description->Name()<<endl;
    XMLElement * language = description->NextSiblingElement();
    cout<<language->GetText()<<endl;
    cout<<language->Name()<<endl;
    XMLElement * copyright = language->NextSiblingElement();
    cout<<copyright->GetText()<<endl;
    cout<<copyright->Name()<<endl;
    XMLElement * pubDate = copyright->NextSiblingElement();
    cout<<pubDate->GetText()<<endl;
    cout<<pubDate->Name()<<endl;
    XMLElement * item=pubDate->NextSiblingElement();

    while(item){
        information  tmp;
        cout<<"sucess in item"<<endl;
        XMLElement *item_child= item->FirstChildElement();
        while(item_child){
            cout<<item_child->GetText()<<endl;
            if(strcmp(item_child->Name(),"title")==0){
//              tmp.title.replace(tmp.title.begin(),tmp.title.end(),item_child->GetText());
                tmp.title.clear();
                tmp.title.append(item_child->GetText());
                cout<<"title-------------------------------------------"<<endl;
            }else if(strcmp(item_child->Name(),"link")==0){
//              tmp.link.replace(tmp.title.begin(),tmp.title.end(),item_child->GetText());
                tmp.link.clear();
                tmp.link.append(item_child->GetText());
                cout<<"link-------------------------------------------"<<endl;
            }else if(strcmp(item_child->Name(),"description")==0){
//              tmp.link.replace(tmp.title.begin(),tmp.title.end(),item_child->GetText());
                tmp.description.clear();
                tmp.description.append(item_child->GetText());
                cout<<"description------------------------------------"<<endl;
            }else if(strncmp(item_child->Name(),"content",7)==0){
//              tmp.content.replace(tmp.title.begin(),tmp.title.end(),item_child->GetText());
                tmp.content.clear();
                tmp.content.append(item_child->GetText());
                cout<<"content------------------------------------"<<endl;
            }else if(strcmp(item_child->Name(),"dc:creator")==0){
//              tmp.dccreator.replace(tmp.title.begin(),tmp.title.end(),item_child->GetText());
                tmp.dccreator.clear();
                tmp.dccreator.append(item_child->GetText());
                cout<<"dc:creator ------------------------------------"<<endl;
            }else if(strcmp(item_child->Name(),"pubdate")==0){
//              tmp.pubdate.replace(tmp.title.begin(),tmp.title.end(),item_child->GetText());
                tmp.pubdate.clear();
                tmp.pubdate.append(item_child->GetText());
                cout<<"pubdate ------------------------------------"<<endl;
            }else if(strcmp(item_child->Name(),"guid")==0){
//              tmp.guid.replace(tmp.title.begin(),tmp.title.end(),item_child->GetText());
                tmp.guid.clear();
                tmp.guid.append(item_child->GetText());
                cout<<"guid------------------------------------"<<endl;
            }
            item_child = item_child->NextSiblingElement();
        }
        information_vector.push_back(tmp);
//      delete tmp;
        item = item->NextSiblingElement();
    }
    traverse(&information_vector);
}

int main()
{
    example1();
    return 0;
}
