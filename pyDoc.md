
###Textwrap module
#####wrap(text, width = 70, **kwargs):这个函数可以把一个字符串拆分成一个序列
  from textwrap import *
  
  #使用textwrap中的wrap()方法
  def test_wrap():
      test_str = '''\
      The textwrap module provides two convenience functions, wrap() and fill(), as well as 1
      TextWrapper, the class that does all the work, and two utility functions, dedent() and indent(). If 2
      you’re just wrapping or filling one or two text strings, the convenience functions should be good 3
      enough; otherwise, you should use an instance of TextWrapper for efficiency. 4
     '''
     print(wrap(test_str, 20))
wrap()函数，把字符串拆分成了一个序列，在这个序列中，每个元素的长度是一样的。

#####fill(text, width=70, **kwargs) :该方法可以根据指定的长度，进行拆分字符串，然后逐行显示
  from textwrap import *
  
  fill()方法
  def test_wrap():
      test_str = '''\
      The textwrap module provides two convenience functions, wrap() and fill(), as well as 1
      TextWrapper, the class that does all the work, and two utility functions, dedent() and indent(). If 2
      you’re just wrapping or filling one or two text strings, the convenience functions should be good 3
      enough; otherwise, you should use an instance of TextWrapper for efficiency. 4
     '''
     print(fill(test_str, 40))
fill(text, width=70, **kwargs) :该方法可以根据指定的长度，进行拆分字符串，然后逐行显示


#####dedent()方法->文本进行不缩进显示，相应的indent()方法 -> 进行缩进显示
  from textwrap import *
  
  dedent()方法
  def test_wrap():
      test_str = '''\
      The textwrap module provides two convenience
          functions, wrap() and fill(), as well as 1
      TextWrapper, the class that does all the work,
          and two utility functions, dedent() and indent(). If 2
     you’re just wrapping or filling one or two text strings,
         the convenience functions should be good 3
     enough; otherwise, you should use an instance
         of TextWrapper for efficiency. 4
     '''
     print(repr(dedent(test_str)))
dedent()方法->文本进行不缩进显示，相应的indent()方法 -> 进行缩进显示


