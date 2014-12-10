<?php

namespace Proc;

/**
 * Worker factory
 *
 * @package Development Notes
 * @author  Jesse Cascio <jessecascio@gmail.com>
 * @see     jessesnet.com/development-notes
 */
class Factory
{	
	/**
	 * Maps types to workers
	 * @var  array
	 */
	private static $workers = [];

	/**
	 * Get the correct worker class
	 * @param  string
	 * @param  array
	 * @throws Exception
	 * @return Worker
	 */
	public static function get($job_type, array $data)
	{
		// store XML config in memory
		if (!count(self::$workers)) {
			$config = simplexml_load_file(__DIR__.'/../../app/config/proc/workers.xml');

			foreach ($config->worker as $worker) {
				$class = (string) $worker->class;
				$type  = (string) $worker->job_type;

				self::$workers[$type] = $class;
			}
		}

		// need flow control if cannot find worker
		if (!isset(self::$workers[$job_type])) {
			throw new \Exception('Worker Does Not Exist');
		}

		$class = __NAMESPACE__.'\\Worker\\'.self::$workers[$job_type];

		// could do further dependency injection here
		return new $class($data);
	}
}