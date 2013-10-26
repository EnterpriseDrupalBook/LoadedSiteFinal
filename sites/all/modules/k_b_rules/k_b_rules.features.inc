<?php
/**
 * @file
 * k_b_rules.features.inc
 */

/**
 * Implements hook_views_api().
 */
function k_b_rules_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function k_b_rules_node_info() {
  $items = array(
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
