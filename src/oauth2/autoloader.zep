
/**
 * Autoloads OAuth2 classes
 *
 * @author    Brent Shaffer <bshafs at gmail dot com>
 * @license   MIT License
 */
namespace OAuth2;

class Autoloader
{
    private dir;

    /**
     * Constructor
     *
     * @param string dir
     */
    public function __construct(string! dir = null)
    {
        if typeof dir == "null" {
            let this->dir = "./";
        } else {
            let this->dir = dir;
        }
    }

    /**
     * Registers OAuth2\Autoloader as an SPL autoloader.
     *
     * @param string dir
     */
    public static function register(string! dir = null) -> void
    {
        ini_set("unserialize_callback_func", "spl_autoload_call");
        spl_autoload_register([new self(dir), "autoload"]);
    }

    /**
     * Handles autoloading of classes.
     *
     * @param string className A class name.
     * @return boolean Returns true if the class has been loaded
     */
    public function autoload(string! className) -> boolean
    {
        var file;

        if 0 !== strpos(className, "OAuth2") {
            return false;
        }

        let file = this->dir . "/" . str_replace("\\", "/", className) . ".php";
        if file_exists(file) {
            require file;
            return true;
        }

        return false;
    }
}
