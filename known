  EAFP:
      try except 

####String
  test a object is a String,or have String's method
  isinstance(obj,basestring)
  why: destroy smooth, unicode-string,string-subclass can not pass the test

  a.join(list) list:[string1,string2]  string1string2
  
  reverse
  rewd = ' '.join(string.split()[::-1])
  
    

XPath:
  <?xml version="1.0" encoding="ISO-8859-1"?>

  <bookstore>

  <book>
    <title lang="eng">Harry Potter</title>
      <price>29.99</price>
  </book>

  <book>
    <title lang="eng">Learning XML</title>
      <price>39.95</price>
  </book>

  </bookstore>

1. bookstore (choose all the son
2. /bookstore (choose the root 
3. //book (choose all the book_sons
4. bookstore//book (choose all the bookstore's sons
5. //@lang (choose lang's attributes

nodename  选取此节点的所有子节点。
/   从根节点选取。
//  从匹配选择的当前节点选择文档中的节点，而不考虑它们的位置。
.   选取当前节点。
..  选取当前节点的父节点。
@   选取属性。

/bookstore/book[last()]  最后一个book元素
/bookstore/book[position()<3]   选取最前面的两个属于 bookstore 元素的子元素的 book 元素。
//title[@lang]  选取所有拥有名为 lang 的属性的 title 元素。
//title[@lang='eng']  选取所有 title 元素，且这些元素拥有值为 eng 的 lang 属性。
/bookstore/book[price>35.00]  选取 bookstore 元素的所有 book 元素，且其中的 price 元素的值须大于 35.00。
/bookstore/book[price>35.00]/title  选取 bookstore 元素中的 book 元素的所有 title 元素，且其中的 price 元素的值须大于 35.00。
选取未知节点

XPath 通配符可用来选取未知的 XML 元素。
通配符  描述
*   匹配任何元素节点。
@*  匹配任何属性节点。
node()  匹配任何类型的节点。
实例

在下面的表格中，我们列出了一些路径表达式，以及这些表达式的结果：
路径表达式  结果
/bookstore/*  选取 bookstore 元素的所有子元素。
//*   选取文档中的所有元素。
//title[@*]   选取所有带有属性的 title 元素。
选取若干路径

通过在路径表达式中使用“|”运算符，您可以选取若干个路径。
实例

在下面的表格中，我们列出了一些路径表达式，以及这些表达式的结果：
路径表达式  结果
//book/title | //book/price   选取 book 元素的所有 title 和 price 元素。
//title | //price   选取文档中的所有 title 和 price 元素。
/bookstore/book/title | //price   选取属于 bookstore 元素的 book 元素的所有 title 元素，以及文档中所有的 price 元素。




XPath 轴

轴可定义相对于当前节点的节点集。
轴名称  结果
ancestor  选取当前节点的所有先辈（父、祖父等）。
ancestor-or-self  选取当前节点的所有先辈（父、祖父等）以及当前节点本身。
attribute   选取当前节点的所有属性。
child   选取当前节点的所有子元素。
descendant  选取当前节点的所有后代元素（子、孙等）。
descendant-or-self  选取当前节点的所有后代元素（子、孙等）以及当前节点本身。
following   选取文档中当前节点的结束标签之后的所有节点。
namespace   选取当前节点的所有命名空间节点。
parent  选取当前节点的父节点。
preceding   选取文档中当前节点的开始标签之前的所有节点。
preceding-sibling   选取当前节点之前的所有同级节点。
self  选取当前节点。
位置路径表达式

位置路径可以是绝对的，也可以是相对的。

绝对路径起始于正斜杠( / )，而相对路径不会这样。在两种情况中，位置路径均包括一个或多个步，每个步均被斜杠分割：
绝对位置路径：

/step/step/...

相对位置路径：

step/step/...

每个步均根据当前节点集之中的节点来进行计算。
步（step）包括：

轴（axis）
    定义所选节点与当前节点之间的树关系
    节点测试（node-test）
        识别某个轴内部的节点
        零个或者更多谓语（predicate）
            更深入地提炼所选的节点集

            步的语法：

            轴名称::节点测试[谓语]

            实例
            例子  结果
            child::book   选取所有属于当前节点的子元素的 book 节点。
            attribute::lang   选取当前节点的 lang 属性。
            child::*  选取当前节点的所有子元素。
            attribute::*  选取当前节点的所有属性。
            child::text()   选取当前节点的所有文本子节点。
            child::node()   选取当前节点的所有子节点。
            descendant::book  选取当前节点的所有 book 后代。
            ancestor::book  选择当前节点的所有 book 先辈。
            ancestor-or-self::book  选取当前节点的所有 book 先辈以及当前节点（如果此节点是 book 节点）
            child::*/child::price   选取当前节点的所有 price 孙节点。
