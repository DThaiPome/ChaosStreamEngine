using Microsoft.AspNetCore.Hosting;
using Microsoft.Extensions.Configuration;
using Microsoft.Extensions.Hosting;
using Microsoft.Extensions.Logging;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace ChaosStreamEngineAPI
{

    public class Program
    {
        [DllImport("ChaosStreamEngineLib.dll")]
        public static extern void StartEngine();
        [DllImport("ChaosStreamEngineLib.dll")]
        public static extern void PushInput(int input);

        public static void Main(string[] args)
        {
            RunAPIAsync(args);
            StartEngine();
        }

        public static IHostBuilder CreateHostBuilder(string[] args) =>
            Host.CreateDefaultBuilder(args)
                .ConfigureWebHostDefaults(webBuilder =>
                {
                    webBuilder.UseStartup<Startup>();
                });

        public static async void RunAPIAsync(string[] args)
        {
            await Task.Run(() => RunAPI(args));
        }

        public static void RunAPI(string[] args)
        {
            CreateHostBuilder(args).Build().Run();
        }
    }
}
