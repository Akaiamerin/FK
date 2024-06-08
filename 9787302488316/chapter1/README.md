### 第 1 章　设计模式概述
1.　设计模式具有（$D$）的优点。

$A.$ 提高系统性能

$B.$ 减少类的数量，降低系统规模

$C.$ 减少代码开发工作量

$D.$ 提升软件设计的质量

<br/>

2.　在面向对象软件开发过程中，采用设计模式（$C$）。

$A.$ 可以减少在设计和实现过程中需要创建的实例对象的数量

$B.$ 可以保证程序的运行速度达到最优值

$C.$ 可以复用相似问题的相同解决方案

$D.$ 允许在非面向对象程序设计语言中使用面向对象的概念

<br/>

3.　（$B$）都是行为型设计模式。

$A.$ 组合模式、适配器模式和代理模式

$B.$ 观察者模式、职责链模式和策略模式

$C.$ 原型模式、建造者模式和单例模式

$D.$ 迭代器模式、命令模式和桥接模式

<br/>

4.　什么是设计模式？它包含哪些基本要素？

设计模式是在特定环境下为解决某一通用软件设计问题提供的一套定制的解决方案，该方案描述了对象和类之间的相互作用。

设计模式包含模式名称、问题、解决方案、效果等基本要素。

<br/>

5.　设计模式如何分类？每一类设计模式有何特点？

<dl>
    设计模式根据目的（模式是用来做什么的）可分为创建型（Creational）、结构型（Structural）、行为性（Behavioral）3 类。
    <dd>创建型模式主要用于创建对象。</dd>
    <dd>结构型模式主要用于处理类或对象的组合。</dd>
    <dd>结构型模式主要用于描述类或对象怎样交互和怎样分配职责。</dd>
</dl>

<dl>
    设计模式根据范围（即模式主要是用于处理类之间的关系还是处理对象之间的关系）可分类模式和对象模式两种。
    <dd>类模式处理类和子类之间的关系，这些关系通过继承建立，在编译时就被确定下来，是一种静态关系。</dd>
    <dd>对象模式处理对象间的关系，这些关系在运行时变化，更具动态性。</dd>
</dl>

<br/>

6.　设计模式具有哪些优点？

设计模式融合了众多专家的经验，并以一种标准的形式供广大开发人员所用，它提供了一套通用的设计词汇和一种通用的语言以方便开发人员之间沟通和交流，使得设计方案更加通俗易懂。

设计模式使人们可以更加简单、方便地复用成功的设计和体系结构，将已证实的技术表述成设计模式也会使新系统开发者更加容易理解其设计模式。

设计模式使得设计方案更加灵活，且易于修改。

设计模式的使用将提高软件系统的开发效率和软件质量，并且一定程度上节约设计成本。

设计模式有助于初学者更深入地理解面向对象思想，一方面可以帮助初学者更加方便地阅读和学习现有类库与其他系统中的源代码，另一方面还可以提高软件的设计水平和代码质量。

<br/>

7.　除了设计模式以外，目前还有不少人在从事“反模式”的研究，请查阅相关资料，了解何谓“反模式”以及研究“反模式”的意义。

反模式（AntiPatterns）是指那些导致开发出现障碍的负面模式，即在软件开发中普遍存在、反复出现并会影响到软件成功开发的不良解决方案。反模式是关注于负面解决方案的软件研究方向揭示出不成功系统中存在的反模式有利于在成功系统中避免出现这些模式，有助于降低软件缺陷和项目失败出现的频率。反模式清晰定义了大部分人在软件开发过程中经常会犯的一些错误，根据视角的不同，可分为开发性反模式、架构性反模式、管理性反模式。

<br/>

8.　请查阅相关资料，了解在 JDK 中使用了哪些设计模式，在何处使用了何种模式，至少列举两个。

创建型模式：

抽象工厂模式（Abstract Factory）：

`java.util.Calendar` 的 `getInstance` 方法。

`java.util.Arrays` 的 `asList` 方法。

`java.util.ResourceBundle` 的 `getBundle` 方法。

`java.net.URL` 的 `openConnection` 方法。

`java.sql.DriverManager` 的 `getConnection` 方法。

`java.sql.Connection` 的 `createStatement` 方法。

`java.sql.Statement` 的 `executeQuery` 方法。

`java.text.NumberFormat` 的 `getInstance` 方法。

`java.lang.management.ManagementFactory` 的所有 `getXXX` 方法。

`java.nio.charset.Charset` 的 `forName` 方法。

`javax.xml.parsers.DocumentBuilderFactory` 的 `newInstance` 方法。

`javax.xml.transform.TransformerFactory` 的 `newInstance` 方法。

`javax.xml.xpath.XPathFactory` 的 `newInstance` 方法。

建造者模式（Builder）：

`java.lang.StringBuilder` 的 `append` 方法。

`java.lang.StringBuffer` 的 `append` 方法。

`java.nio.ByteBuffer`、`java.nio.CharBuffer`、`java.nio.ShortBuffer`、`java.nio.IntBuffer`、`java.nio.LongBuffer`、`java.nio.FloatBuffer`、`java.nio.DoubleBuffer` 的 `put` 方法。

`javax.swing.GroupLayout.Group` 的 `addComponent` 方法。

`java.sql.PreparedStatement`。

`java.lang.Appendable` 的所有实现类。

工厂方法模式（Factory Method）：

`java.lang.Object` 的 `toString` 方法。

`java.lang.Class` 的 `newInstance` 方法。

`java.lang.Boolean`、`java.lang.Byte`、`java.lang.Character`、`java.lang.Short`、`java.lang.Integer`、`java.lang.Long`、`java.lang.Float`、`java.Double` 的 `valueOf` 方法。

`java.lang.Class` 的 `forName` 方法。

`java.lang.reflect.Array` 的 `newInstance` 方法。

`java.lang.reflect.Constructor` 的 `newInstance` 方法。

原型模式（Prototype）：

`java.lang.Object` 的 `clone` 方法。

单例模式（Singleton）：

`java.lang.Runtime` 的 `getRuntime` 方法。

`java.awt.Desktop` 的 `getDesktop` 方法。

结构型模式：

适配器模式（Adapter）：

`java.util.Arrays` 的 `asList` 方法。

`javax.swing.JTable`。

`java.io.InputStreamReader`。

`java.io.OutputStreamWriter`。

`javax.xml.bind.annotation.adapters.XmlAdapter` 的 `marshal` 方法。

`javax.xml.bind.annotation.adapters.XmlAdapter` 的 `unmarshal` 方法。

桥接模式（Bridge）：

AWT。

JDBC。

组合模式（Composite）：

`javax.swing.JComponent` 的 `add` 方法。

`java.awt.Container` 的 `add` 方法。

`java.util.List` 的 `addAll` 方法。

`java.util.Set` 的 `addAll` 方法。

`java.util.Map` 的 `putAll` 方法。

装饰模式（Decorator）：

`java.io.BufferedInputStream`。

`java.io.BufferedOutputStream`。

`java.io.DataInputStream`。

`java.util.zip.ZipOutputStream`。

`java.util.Collections` 的 `checkedList` 方法。

`java.util.Collections` 的 `checkedSet` 方法。

`java.util.Collections` 的 `checkedMap` 方法。

`java.util.Collections` 的 `checkedSortedSet` 方法。

`java.util.Collections` 的 `checkedSortedMap` 方法。

外观模式（Facade）：

`java.lang.Class`。

`javax.faces.webapp.FacesServlet`。

享元模式（Flyweight）：

`java.lang.Boolean` 的 `valueOf` 方法。

`java.lang.Byte` 的 `valueOf` 方法。

`java.lang.Character` 的 `valueOf` 方法。

`java.lang.Integer` 的 `valueOf` 方法。

代理模式（Proxy）：

`java.lang.reflect.Proxy`。

`java.rmi.*`。

行为型模式：

职责链模式（Chain of Responsibility）：

`java.util.logging.Logger` 的 `log`  方法。

`javax.servlet.Filter` 的 `doFilter` 方法。

命令模式（Command）：

`java.lang.Runnable`。

`javax.swing.Action`。

解释器模式（Interpreter）：

`java.util.Pattern`。

`java.text.Normalizer`。

`java.text.Format`。

`javax.el.ELResolver`。

迭代器模式（Iterator）：

`java.util.Iterator`。

`java.util.Enumeration`。

中介者模式（Mediator）：

`java.util.Timer` 的所有 `scheduleXXX` 方法。

`java.util.concurrent.Executor` 的 `execute` 方法。

`java.util.concurrent.ExecutorService` 的所有 `invokeXXX` 方法和 `submit` 方法。

`java.util.concurrent.ScheduledExecutorService` 的所有 `scheduleXXX` 方法。

`java.lang.reflect.Method` 的 `invoke` 方法。

备忘录模式（Memento）：

`java.util.Date`。

`java.io.Serializable`。

`javax.faces.component.StateHolder`。

观察者模式（Observer）：

`java.util.Observer`、`java.util.Observable`。

`java.util.EventListener` 的所有子类。

`javax.servlet.http.HttpSessionBindingListener`。

`javax.servlet.http.HttpSessionAttributeListener`。

`javax.faces.event.PhaseListener`。

状态模式（State）：

`java.util.Iterator`。

`javax.faces.lifecycle.LifeCycle` 的 `execute` 方法。

策略模式（Strategy）：

`java.util.Comparator` 的 `compare` 方法。

`javax.servlet.http.HttpServlet`。

`javax.servlet.Filter` 的 `doFilter`方法。

模板方法模式（Template Method）：

`java.io.InputStream`、`java.io.OutputStream`、`java.io.Reader`、`java.io.Writer` 的所有非抽象方法。

`java.util.AbstractList`、`java.util.AbstractSet`、`java.util.AbstractMap` 的所有非抽象方法。

`javax.servlet.http.HttpServlet` 的所有 `doXXX` 方法。

访问者模式（Visitor）：

`javax.lang.model.element.AnnotationValue`、`javax.lang.model.element.AnnotationValueVisitor`。

`javax.lang.model.element.Element`、`javax.lang.model.element.ElementVisitor`。

`javax.lang.model.type.TypeMirror`、`javax.lang.model.type.TypeVisitor`。