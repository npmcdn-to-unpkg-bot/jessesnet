<?php

namespace test\Service;

use Service;

/**
 * Supervisor Test
 *
 * @package Development Notes
 * @author  Jesse Cascio <jessecascio@gmail.com>
 * @see     jessesnet.com/development-notes
 */
class SupervisorTest extends \PHPUnit_Framework_TestCase
{	
	protected $Log;

	protected function setUp()
	{
		$DIContainer = new Service\Container();
		$this->Log   = $DIContainer->get('logger');
		// wouldnt be hard coded here, in a config file
		$this->path = __DIR__."/../../logs/test_".md5(microtime()).".log";
		$this->Log->path($this->path);
	}

	public function testInfo()
	{	
		$this->Log->info('stuff');
		$this->assertTrue(file_exists($this->path));
	}

	public function testError()
	{	
		$this->Log->error('stuff');
		$this->assertTrue(file_exists($this->path));
	}

	public function tearDown()
	{
		unlink($this->path);
	}
} 