<?php

namespace test\Proc;

use Proc;

/**
 * Factory Test
 *
 * @package Development Notes
 * @author  Jesse Cascio <jessecascio@gmail.com>
 * @see     jessesnet.com/development-notes
 */
class FactoryTest extends \PHPUnit_Framework_TestCase
{	
	public function testFactoryGet()
	{
		$this->assertInstanceOf('Proc\Worker\APIClient', Proc\Factory::get('api_call', []));
		$this->assertInstanceOf('Proc\Worker\Worker', Proc\Factory::get('api_call', []));
	}

	/**
	 * @expectedException \Exception
	 */
	public function testFactoryFail()
	{
		Proc\Factory::get('api_callz', []);
	}
} 