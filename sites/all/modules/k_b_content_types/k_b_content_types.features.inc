<?php
/**
 * @file
 * k_b_content_types.features.inc
 */

/**
 * Implements hook_node_info().
 */
function k_b_content_types_node_info() {
  $items = array(
    'menu' => array(
      'name' => t('Menu'),
      'base' => 'node_content',
      'description' => t('The online menu for the restaurant. Can be used by several or even all locations.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'menu_item' => array(
      'name' => t('Menu Item'),
      'base' => 'node_content',
      'description' => t('Any item sold in the restaurant is a menu item, including drinks.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'restaurant_branch' => array(
      'name' => t('Restaurant Branch'),
      'base' => 'node_content',
      'description' => t('A branch of the K&B Restaurants franchise'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'special' => array(
      'name' => t('Special'),
      'base' => 'node_content',
      'description' => t('For a duration of time, at select restaurants, for select menu items.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
