﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using NUnit.Framework;


namespace Lampes
{
    class Program
    {
        static void Main(string[] args)
        {
            Test.test();
            Assert.AreEqual(1, 1);
            Console.ReadKey();
        }
    }
}
