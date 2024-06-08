### 第 8 章　单例模式
1.　在（$B$）时可使用单例模式。

$A.$ 隔离菜单项对象的创建和使用

$B.$ 防止一个资源管理器窗口被实例化多次

$C.$ 使用一个已有的查找算法而不想修改既有代码

$D.$ 不能创建子类，需要扩展一个数据过滤类

<br/>

2.　以下关于单例模式的描述正确的是（$B$）。

$A.$ 它描述了只有一个方法的类的集合

$B.$ 它能够保证一个类只产生一个唯一的实例

$C.$ 它描述了只有一个属性的类的集合

$D.$ 它能够保证一个类的方法只能被一个唯一的类调用

<br/>

3.　以下（$B$）不是单例模式的要点。

$A.$ 某个类只能有一个实例

$B.$ 单例类不能被继承

$C.$ 必须自行创建单个实例

$D.$ 必须自行向整个系统提供单个实例

<br/>

4.　分析并理解饿汉式单例与懒汉式单例的异同。

饿汉式单例类在被加载时就讲自己实例化，它的优点在于无须考虑多个线程同时访问的问题，可以确保实例的唯一性；从调用速度和反应时间角度来讲，由于单例对象一开始就得以创建，因此要优于懒汉式单例。但是无论系统在运行时是否需要使用该单例对象，由于在类加载时该对象就需要创建，因此从资源利用效率角度来讲饿汉式单例不及懒汉式单例，而且在系统加载时由于需要创建饿汉式单例对象，加载时间可能会比较长。

懒汉式单例在第一次运行时创建，无须一直占用系统资源，实现了延迟加载，但是必须处理多个线程同时访问的问题，特别是当单例类作为资源控制器，在实例化是必然涉及资源初始化，而资源初始化很有可能耗费大量时间，这意味着出现多线程同时首次引用此类的几率变得较大，需要通过双重检查锁定等机制进行控制，这将导致系统性能受到一定影响。

<br/>

5.　什么是双重检查锁定？为什么要进行双重检查锁定？Java 如何实现双重检查锁定？

略。

<br/>

6.　分别采用双重检查锁定和 IoDH 方式实现 8.3 节的负载均衡器。

```Java
public class LoadBalancer {
    private volatile static LoadBalancer loadBalancer = null;
    private LoadBalancer() {

    }
    public static LoadBalancer getLoadBalancer() {
        if (loadBalancer == null) {
            synchronized (LoadBalancer.class) {
                if (loadBalancer == null) {
                    loadBalancer = new LoadBalancer();
                }
            }
        }
        return loadBalancer;
    }
}
```

```Java
public class LoadBalancer {
    private static class HolderClass {
        private static final LoadBalancer loadBalancer = new LoadBalancer();
    }
    private LoadBalancer() {

    }
    public static LoadBalancer getLoadBalancer() {
        return HolderClass.loadBalancer;
    }
}
```

<br/>

7.　使用单例模式设计一个多文档窗口（注：在 Java AWT/Swing 开发中可使用 JDesktopPane 和 JInternalFrame 来实现），要求在主窗体中某个内部子窗体只能实例化一次，即智能弹出一个相同的子窗体，如图 8-6 所示，编程实现该功能。

略。

<br/>

8.　某软件公司开发人员要创建一个数据库连接池，将指定个数的（如两个或 3 个）数据库连接对象存储在连接池中，客户端代码可以从池中随机取一个连接对象来连接数据库。试通过对单例类进行改造，设计一个能够自行提供指定个数实例对象的数据库连接类并用 Java 代码编程模拟。

![](./img/img1.png)

```Java
public class Multiton {
    private static Multiton[] arr = new Multiton[]{
            new Multiton(),
            new Multiton(),
            new Multiton()
    };
    private Multiton() {

    }
    public static Multiton getInstance() {
        int index = new Random().nextInt(0, arr.length);
        return arr[index];
    }
}
```