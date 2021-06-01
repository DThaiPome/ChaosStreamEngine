using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace ChaosStreamEngineAPI.Controllers
{
    [ApiController]
    [Route("[controller]/[action]")]
    public class EngineController : Controller
    {
        public IActionResult Index()
        {
            return View();
        }

        [HttpGet]
        public int Test()
        {
            return Program.GetCount();
        }
    }
}
