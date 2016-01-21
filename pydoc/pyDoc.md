
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


#####装饰器
    def log(text):
    def decorator(func):
        def wrapper(*args, **kw):
            print '%s %s():' % (text, func.__name__)
            return func(*args, **kw)
        return wrapper
    return decorator

    
######偏函数    
    functools.partial就是帮助我们创建一个偏函数的，不需要我们自己定义int2()，可以直接使用下面的代码创建一个新的函数int2：

    >>> import functools
    >>> int2 = functools.partial(int, base=2)
    >>> int2('1000000')
    64
    >>> int2('1010101')
    85

######logging 线程安全模块
logging.basicConfig函数各参数:
filename: 指定日志文件名
filemode: 和file函数意义相同，指定日志文件的打开模式，'w'或'a'
format: 指定输出的格式和内容，format可以输出很多有用信息，如上例所示:
%(levelno)s: 打印日志级别的数值
%(levelname)s: 打印日志级别名称
%(pathname)s: 打印当前执行程序的路径，其实就是sys.argv[0]
%(filename)s: 打印当前执行程序名
%(funcName)s: 打印日志的当前函数
%(lineno)d: 打印日志的当前行号
%(asctime)s: 打印日志的时间
%(thread)d: 打印线程ID
%(threadName)s: 打印线程名称
%(process)d: 打印进程ID
%(message)s: 打印日志信息
datefmt: 指定时间格式，同time.strftime()
level: 设置日志级别，默认为logging.WARNING
stream: 指定将日志的输出流，可以指定输出到sys.stderr,sys.stdout或者文件，默认输出到sys.stderr，当stream和filename同时指定时，stream被忽略
