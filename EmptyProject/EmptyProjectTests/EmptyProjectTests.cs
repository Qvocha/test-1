using Microsoft.VisualStudio.TestTools.UnitTesting;
using EmptyProject;

namespace EmptyProjectTests
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod1()
        {
            Assert.AreEqual(3, Calculator.Addition(1, 2));
        }
    }
}
