//
//  main.cpp
//  decorator
//
//  Created by 胡二雷 on 2018/9/22.
//  Copyright © 2018年 胡二雷. All rights reserved.
//

#include <iostream>
#include "decorator.h"

using namespace decorator;

int main(int argc, const char * argv[]) {
  // insert code here...
  Content *wordcontent = new WordsContent();
  Content *imagecontent = new ImagesContent();
  Content *movedecorator = new MoveDecorator(*wordcontent);
  Content *resizedecorator = new ResizeDecorator(*imagecontent);
  movedecorator->display();
  resizedecorator->display();
  return 0;
}
