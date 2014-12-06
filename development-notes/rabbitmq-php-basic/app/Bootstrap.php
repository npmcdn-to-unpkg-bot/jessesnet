<?php

namespace app;

/**
 * Bootstrap Application
 *
 * @package Development Notes
 * @author  Jesse Cascio <jessecascio@gmail.com>
 * @see     jessesnet.com/development-notes
 */
abstract class Bootstrap
{
	/**
	 * Bootstrap application
	 */
	public static function init()
	{
		self::initAutoload();
		self::loadConfig();
	}

	/**
	 * Set up autoloading
	 */
	private static function initAutoload()
	{
		require __DIR__ . "/../vendor/autoload.php";
	}

	/**
	 * Load the environment vars
	 */
	private static function loadConfig()
	{
		// check for local copy, default to development
		if (file_exists(__DIR__ . "/config/config.php")) {
			require __DIR__ . "/config/config.php";
		} else {
			require __DIR__ . "/config/config.development.php";
		}
	}
}
