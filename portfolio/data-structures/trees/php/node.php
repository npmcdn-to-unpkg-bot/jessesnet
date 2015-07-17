<?php

class Node
{
	private $value;

	private $parent;

	private $children;

	public function value($value)
	{
		$this->value = $value;
	}

	public function parent(Node $parent)
	{
		$this->parent = $parent;
	}

	public function child(Node $child)
	{
		$this->children[] = $child;
	}

	public function firstChild()
	{
		return $this->children[0];
	}

	public function secondChild()
	{
		return $this->children[1];
	}

	public function children()
	{
		return $this->children;
	}

	public function isFull()
	{
		if (isset($this->children) && count($this->children) == 2) {
			return true;
		}

		return false;
	}

	public function isRoot()
	{
		if (!isset($this->parent)) {
			return true;
		}

		return false;
	}
}