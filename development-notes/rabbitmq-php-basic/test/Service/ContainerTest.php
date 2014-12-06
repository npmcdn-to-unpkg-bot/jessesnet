<?php

namespace test\Service;

use Service;

/**
 * Service Container Test
 *
 * @package Development Notes
 * @author  Jesse Cascio <jessecascio@gmail.com>
 * @see     jessesnet.com/development-notes
 */
class ContainerTest extends \PHPUnit_Framework_TestCase
{	
	protected $DIContainer;

	protected function setUp()
	{
		$this->DIContainer = new Service\Container();
	}

	public function testRabbitClient()
	{
		$this->assertInstanceOf('Broker\RabbitClient', $this->DIContainer->get('rabbit-client'));
	}
} 