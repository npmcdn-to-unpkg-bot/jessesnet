<?php

require_once 'node.php';

class Tree
{
	private $root;

	private $leaf;

	public function add($val)
	{
		$node = new Node();

		if (is_null($this->root)) {
			$root = $node;
			$root->value($val);

			$this->leaf = $root;

			return;
		}

		if (!$this->leaf->isFull()) {
			$this->leaf->child($node);
			return;
		}	
		

	}

	public function root()
	{
		return $this->root;
	}

	/*
	public function parent()
	{

	}

	public function children()
	{

	}

	public function isInternal()
	{

	}

	public function isExternal()
	{

	}

	public function isRoot()
	{

	}

	public function size()
	{

	}
	*/
}