namespace InputSystem
{
    public class InputSystem
    {
        public static InputSystem Instance { get; private set; } = new InputSystem();

        public void Update()
        {
            var key = Console.ReadKey();
        }
    }
}