//
//  decorator.h
//  decorator
//
//  Created by 胡二雷 on 2018/9/22.
//  Copyright © 2018年 胡二雷. All rights reserved.
//

#ifndef decorator_h
#define decorator_h
#include<iostream>

namespace decorator {
  

class Content{
 public:
  Content(){
    std::cout<<"building content"<<std::endl;
  }
  virtual ~Content(){
    
  }
  virtual void display(){
    std::cout<<"content display"<<std::endl;
  }
};

class WordsContent : public Content{
public:
  WordsContent(){
    std::cout<<"wordscontent building" << std::endl;
  }
  void display() override;
};

void WordsContent::display(){
  std::cout << "wordscontent display" << std::endl;
}
  
class ImagesContent : public Content {
 public:
  ImagesContent(){
    std::cout << "imagescontent building";
  }
  void display() override;
};
  
void ImagesContent::display(){
    std::cout << "imagescontent display" << std::endl;
}

class Decorator : public Content{
 public:
  Decorator(Content content) : content_instance(content) {
    std::cout << "Decorator building" << std::endl;
  }
  virtual void display(){
    content_instance.display();
    std::cout << "decorator display" << std::endl;
  }
  virtual ~Decorator(){}
 private:
  Content content_instance;
};
  
class MoveDecorator : public Decorator{
public:
  explicit MoveDecorator(const Content& content) : Decorator(content){
    //super(content);
    std::cout << "MoveDecorator building" << std::endl;
  }
  void display() override {
    Decorator::display();
    std::cout << "movedecorator display" << std::endl;
  }
};
  
class ResizeDecorator : public Decorator {
public:
  explicit ResizeDecorator(const Content& content) : Decorator(content){
    //super(content);
    std::cout << " ResizeDecorator building " << std::endl;
  }
  void display() override {
    Decorator::display();
    std::cout << "ResizeDecorator display" << std::endl;
  }
};
  
} //namespace decorator
#endif /* decorator_h */
